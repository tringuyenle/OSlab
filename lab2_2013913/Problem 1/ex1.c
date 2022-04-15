#include "ex1.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* aligned_malloc(unsigned int size, unsigned int align) {
	if (size <= 0 || align <= 0)
		return NULL;

	void* ptr;
	int offset;
	ptr = malloc(size);
	if (!ptr)
		return NULL;

	offset = (uintptr_t)ptr % align;
	if (offset != 0) 
		return aligned_malloc(size, align);

	return ptr;
}

void* aligned_free(void* ptr) {
	free(ptr);
	return NULL;
}
