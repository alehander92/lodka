#! /bin/bash 

set -e


nim c --os:any --gc:arc -d:danger --compileOnly:on -d:StandaloneHeapSize:4096 --exceptions:goto -d:nimNoLibc -d:nimNoSignalHandler --noMain --nimcache:build start.nim



# cd asm
# assembly=(./c*.s)
# cd ..
# nasm -felf32 asm/boot.s -o build/boot.o
~/opt/cross/bin/i686-elf-as asm/boot.s -o build/boot.o
# for file in "${assembly[@]}"; do
  # credit https://stackoverflow.com/questions/2664740/extract-file-basename-without-path-and-extension-in-bash
  # ~/opt/cross/bin/i686-elf-as asm/$file -o build/${file%.s}.o
# done

cp c/libc.c build/

cd build
files=(./*.c)
cd ..
echo $files
for file in "${files[@]}"; do
  echo $file
  # based on this tutorial http://www.osdever.net/bkerndev/Docs/keyboard.htm # -fno-strict-aliasing
  ~/opt/cross/bin/i686-elf-gcc -c -w -ffreestanding -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdlib -nostdinc -fno-builtin -m32 -g3 -gdwarf -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L./c -I./c -o build/$file.o build/$file
done



mv build/boot.o /tmp
objects=(build/*.o)
mv /tmp/boot.o build/

# credit https://stackoverflow.com/questions/13470413/converting-a-bash-array-into-a-delimited-string
printf -v objects2 ' %s' "${objects[@]}"
echo $objects2
~/opt/cross/bin/i686-elf-gcc -T linker.ld  -o build/start.bin -z max-page-size=0x1000 -ffreestanding -g3 -gdwarf -nostdlib build/boot.o $objects2

