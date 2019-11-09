#include <stddef.h>

// TODO: wip

int HEAP = 50000000;

void memset (void* a, int value, size_t size) {
	char* a2 = a;
	for(int i = 0; i < size; i += 1) {
		a2[i] = value;
	}
}

void* malloc(size_t size) {
	int res = HEAP;
	HEAP += size;
	return (void*)res;
}

void* realloc(void* a, size_t size) {
	char* a2;
	*a2 = malloc(size);
	return (void*)a2;
}


void* memcpy(void* a, void* b, size_t size) {
	char* a2 = a;
	char* b2 = b;
	for(int i = 0; i < size; i += 1) {
		a2[i] = b2[i];
	}
}


void exit() {}
void free(void* a) {
	return;
}

int setjmp() {return 0;}

int strlen(char* a) {
	int res = 0;
	int index = 0;
	while (1) {
		if (a[index] != '\0') {
			res += 1;
		} else {
			break;
		}

	}
	return res;
}

int fwrite() {return 1;}

