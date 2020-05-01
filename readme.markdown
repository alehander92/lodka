# study-kernel

A small kernel in nim, started as a fork of [@dom96 's nimkernel](https://github.com/dom96/nimkernel)

It is also inspired by [Samantha Doran 's Mero](https://github.com/samanthadoran/Mero) : credits to them!
However I wanted to know learn how this gdt etc stuff happens and write it down in a library and to stop using the Mero source


It is also based on many osdev and other internet articles: 


* [Writing an OS in Rust by Philipp Oppermann](https://os.phil-opp.com/)
* [How to create an OS from scratch repo by Carlos Fenollosa](https://github.com/cfenollosa/os-tutorial)
* and others TODO

# why

Praise God! learning and building things is just fun and i want to somehow learn a bit more about os dev and language <=> os combinations.


# structure

TODO structure

`start.nim` => contains kmain and registers the main code for now
`console.nim` => a console utils module mostly from `nimkernel` by @dom96
`ioutils.nim` => a console ioutils module with code mostly from `nimkernel` by @dom96 iirc
`panicoverride.nim` => a panic override module with code mostly from `nimkernel` by @dom96 or `Mero` by Samantha Doran, not sure
`asm/` => assembly sources needed for the kernel, most of them are from `nimkernel`/`Mero` or `osdev`
`c/` => c sources needed for the kernel
`build/` => build files

`Dockerfile` => dockerfile for kernel
`nim.cfg` => nim config
`build_nim.sh` => a build script
`linker.ld`, `linker2.ld` => linker files, not sure which one is important
`nakefile.nim` => older nake file based on `nimkernel` / `Mero` stuff IIRC

`LICENSE` => study-kernel current GPL3 license
`Mero_LICENSE` => `Mero` GPL3 license
`nimkernel_LICENSE` => `nimkernel` MIT license


`asm/`:
* `boot.s`: taken from `Mero` i think
* `crti.s`: from `Mero`(maybe `osdev`?) crtbegin stuff
* `ctrn.s`: from `Mero`(maybe `osdev`?) ctrend stuff?
* `a.s`: not sure, maybe test

`c/`:
* `libc.c`: our version of libc 
* `nimbase.h`: the header file from `nim` repo
* `setjmp.h`: our setjmp header
* `signal.h`: ..

sorry, the repo is not well done, so i had to git init again, but its based on nimkernel code and Mero code

# how

run the nim build with (change to your path)

```bash
bash build_nim.sh
qemu-system-i386 -kernel build/start.bin
```


# TODO 

* study from https://github.com/cfenollosa/os-tutorial and others
* interrupt handling: was initially copied from Mero, now I stop importing that and want to write it again
* multitasking: await/async? probably preemptive, want to have "type safe" processes instead of memory protection

* permissions? processes?
* think more shell?
* database-like filesystem api: probably for now in memory without driver
* networking: tcp stack .. complicated