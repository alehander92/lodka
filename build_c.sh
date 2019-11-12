#! /bin/bash 

set -e
# credit https://stackoverflow.com/questions/21668471/bash-script-create-array-of-all-files-in-a-directory
files=(./*.c)
for file in "${files[@]}"; do
  echo $file
  # based on this tutorial http://www.osdever.net/bkerndev/Docs/keyboard.htm # -fno-strict-aliasing
  i686-elf-gcc -c  -w -ffreestanding -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdlib -nostdinc -fno-builtin -m32 -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/lodka -I/lodka -o $file.o $file
done
mv boot.o /tmp
objects=(./*.o)
mv /tmp/boot.o .

# sudo cp /usr/bin/as2 /usr/bin/as
# credit https://stackoverflow.com/questions/13470413/converting-a-bash-array-into-a-delimited-string
printf -v objects2 ' %s' "${objects[@]}"
echo $objects2
i686-elf-gcc -T linker.ld -o a.bin -z max-page-size=0x1000 -ffreestanding -g3 -nostdlib boot.o $objects2
