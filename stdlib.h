#ifndef _STDLIB_H
#define _STDLIB_H 1

void __divdi3();
int signal();
void longjmp();
void* calloc2();
void* calloc(size_t size, size_t size2);

int fflush();

const int SIGINT;
const int SIGSEGV;
const int SIGABRT;
const int SIGFPE;
const int SIGILL;
// typedef int size_t;


#endif