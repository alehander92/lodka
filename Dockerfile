FROM joshwyant/gcc-cross

COPY . nimkernel
COPY nim nim
RUN apt install -y strace
WORKDIR nim
RUN sh build_all.sh
WORKDIR nimkernel

CMD strace i686-elf-gcc -c  -w -w -I$lib -ffreestanding -O2 -Wall -Wextra -O3 -fno-strict-aliasing  -I./lib -I. -o main_r/stdlib_system.c.o main_r/stdlib_system.c
