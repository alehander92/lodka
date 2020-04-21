#! /bin/bash 

set -e

nim c -f -c -d:danger --boundChecks:off --overflowChecks:off --gc:arc --nimcache:nimcache a.nim
assembly=(./c*.s)
nasm -felf32 boot.s -o boot.o
for file in "${assembly[@]}"; do
  # credit https://stackoverflow.com/questions/2664740/extract-file-basename-without-path-and-extension-in-bash
  i686-elf-as $file -o ${file%.s}.o
done

cp nimcache/@ma.nim.c a2.c
cp nimcache/stdlib_system.nim.c .
cp nimcache/stdlib_allocators.nim.c .
cp nimcache/@mMero@ssource@sasmwrapper.nim.c .
cp nimcache/@mMero@ssource@sgdt.nim.c .
cp nimcache/@mMero@ssource@sidt.nim.c .
cp nimcache/@mMero@ssource@sirq.nim.c .
cp nimcache/@mMero@ssource@sisrs.nim.c .
cp nimcache/@mconsole.nim.c .
cp nimcache/@mMero@ssource@skeyboard.nim.c .
