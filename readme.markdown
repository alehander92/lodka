# kernel

a small kernel in nim, started as a fork of [@dom96 's nimkernel](https://github.com/dom96/nimkernel) and [Samantha Doran 's Mero](https://github.com/samanthadoran/Mero) : credits to them!

also based on many osdev and other internet articles

sorry, the repo is not well done, so i had to git init again, but its based on nimkernel code and Mero code

# how

run the nim build with (change to your path)

```bash
bash build_nim.sh
docker run -v /home/al/lodka:/lodka -it joshwyant/gcc-cross
```
then run in the docker container 

```bash
cd /lodka
bash build_c.sh
```

and finally `qemu-system-i386 -kernel a.bin`

# TODO 

link my nim fork `kernel` patch : you need to compile the kernel, currently in my github


* interrupt handling: currently copied from Mero, but i need to start understanding it
* multitasking: probably preemptive, want to have "type safe" processes instead of memory protection
* database-like filesystem api: probably for now in memory without driver
* networking: tcp stack .. complicated