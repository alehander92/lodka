ery simple custom MBR that loads a kernel in protected mode at 0x7E00, you can debug both with something like:

add-symbol-file stage0.elf 0x7c00
add-symbol-file stage1.elf 0x7e00
target remote | qemu -S -gdb stdio -m 16 -boot c -hda drive0.img
