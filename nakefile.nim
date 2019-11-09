import nake
import os

const
  CC = "i686-elf-gcc"
  asmC = "i686-elf-as"

task "clean", "Removes build files.":
  removeFile("boot.o")
  removeFile("main.bin")
  removeDir("nimcache")
  echo "Done."

task "build", "Builds the operating system.":
  echo "Compiling..."
  direShell "sudo cp /usr/bin/" & asmC & " /usr/bin/as"
  echo "~/nim/compiler/nim c --debugInfo --lineDir:o --passC:'-I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel' --gcc.exe:$1 main.nim" % CC
  discard execShellCmd "~/nim/compiler/nim c --debugInfo --lineDir:on --passC:'-I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel' --gcc.exe:$1 main.nim" % CC
  direShell CC, "-c  -w -w -I$lib -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -O3 -fno-strict-aliasing  -I/home/al/nim/lib -I/home/al/nimkernel -o libc.c.o libc.c"
  direShell "sudo cp /usr/bin/as2 /usr/bin/as"
  
  direShell asmC, "boot.s -o boot.o"
  
  echo "Linking..."
  
  echo CC & " -T linker.ld -o main.bin -ffreestanding -O2 -nostdlib boot.o -L/home/al/nimkerne nimcache/main.c.o nimcache/stdlib_system.c.o nimcache/ioutils.c.o"
  direShell CC, "-T linker.ld -o main.bin -ffreestanding -O2 -nostdlib boot.o -L/home/al/nimkernel libc.c.o nimcache/main.c.o nimcache/stdlib_system.c.o nimcache/ioutils.c.o"
  echo "Done."
  
task "run", "Runs the operating system using QEMU.":
  if not existsFile("main.bin"): runTask("build")
  direShell "qemu-system-i386 -kernel main.bin"


# sudo cp /usr/bin/i686-elf-as /usr/bin/as
# i686-elf-gcc -c  -w -w -I$lib -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -fno-strict-aliasing -I/home/al/nimkernel -o libc.c.o libc.c
# i686-elf-gcc -c  -w -w -I$lib -ffreestanding -g3 -Wall -Wextra -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include-fixed/ -I/usr/local/cross/lib/gcc/i686-elf/8.1.0/include/ -L/home/al/nimkernel -fno-strict-aliasing -I/home/al/nimkernel -o a.c.o a.c
# sudo cp /usr/bin/as2 /usr/bin/as
# i686-elf-gcc -T linker.ld -o a.bin -ffreestanding -g3 -nostdlib boot.o a.c.o libc.c.o