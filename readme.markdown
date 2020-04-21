# study-kernel

A small kernel in nim, started as a fork of [@dom96 's nimkernel](https://github.com/dom96/nimkernel) and [Samantha Doran 's Mero](https://github.com/samanthadoran/Mero) : credits to them!

It is also based on many osdev and other internet articles: 

* [Writing an OS in Rust by Philipp Oppermann](https://os.phil-opp.com/)
* and others TODO

# why

Praise God! learning and building things is just fun and i want to somehow learn a bit more about os dev and language <=> os combinations.


# structure

TODO structure

`start.nim` => contains kmain and registers the main code for now
`Mero/` => contains a lot of the `Mero` code : TODO move it to small lib/libs 
`asm/` => assembly sources needed for the kernel, most of them are from `nimkernel`/`Mero` or `osdev`

`c/` => c sources needed for the kernel
`Dockerfile` => dockerfile for kernel
`nim.cfg` => nim config
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
docker run -v /home/al/study-kernel:/study-kernel -it joshwyant/gcc-cross
```
then run in the docker container 

```bash
cd /study-kernel
bash build_c.sh
```

and finally `qemu-system-i386 -kernel a.bin`


# TODO 

link my nim fork `kernel` patch : you need to compile the kernel, currently in my github


* interrupt handling: currently copied from Mero, but i need to start understanding it
* multitasking: probably preemptive, want to have "type safe" processes instead of memory protection
* database-like filesystem api: probably for now in memory without driver
* networking: tcp stack .. complicated