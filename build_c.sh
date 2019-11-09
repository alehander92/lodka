#! /bin/bash 

set -e
# credit https://stackoverflow.com/questions/21668471/bash-script-create-array-of-all-files-in-a-directory
files=(./*.c) #"libc.c" "a2.c" "stdlib_allocators.nim.c" "stdlib_system.nim.c")
for file in "${files[@]}"; do
  echo $file
  i686-elf-gcc -c  -w -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -fno-strict-aliasing -I/home/al/nimkernel -o $file.o $file
done
objects=(./*.o)
# i686-elf-gcc -c  -w -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -fno-strict-aliasing -I/home/al/nimkernel -o libc.c.o libc.c
# i686-elf-gcc -c  -w -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -fno-strict-aliasing -I/home/al/nimkernel -o a2.c.o a2.c
# i686-elf-gcc -c  -w -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -fno-strict-aliasing -I/home/al/nimkernel -o stdlib_allocators.nim.c.o stdlib_allocators.nim.c
# i686-elf-gcc -c  -w -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -fno-strict-aliasing -I/home/al/nimkernel -o stdlib_system.nim.c.o stdlib_system.nim.c


# sudo cp /usr/bin/as2 /usr/bin/as
# credit https://stackoverflow.com/questions/13470413/converting-a-bash-array-into-a-delimited-string
printf -v objects2 ' %s' "${objects[@]}"
echo $objects2
i686-elf-gcc -T linker.ld -o a.bin -ffreestanding -g3 -nostdlib $objects2
# a2.c.o stdlib_system.nim.c.o stdlib_allocators.nim.c.o libc.c.o