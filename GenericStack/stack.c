//stack.c
#include "stack.h"

void stackCreate(stack *s, int elementSize) {
	assert(elementSize > 0);

	s->elementSize = elementSize;
	s->logLength = 0;
	s->allocLength = kInitialAllocationSize;
	s->elements = malloc(kInitialAllocationSize * elementSize);
	
	assert(s->elements != NULL);
}

void stackDestroy(stack *s) {
	free(s->elements);
}

bool stackEmpty(const stack *s) {
	return s->logLength == 0;
}

// Push dynamically reallocates the array if needed to be larger.
bool stackPush(stack *s, const void *elementAddr) {
	if (s->logLength == s->allocLength) {
		s->allocLength *= 2;
		s->elements = realloc(s->elements, s->allocLength * s->elementSize);
		//assert(s->elems != NULL);
		if (s->elements == NULL)
			return false;
	}
	void *destAddr = (char *)s->elements + s->logLength * s->elementSize;
	memcpy(destAddr, elementAddr, s->elementSize);
	s->logLength++;
	return true;
}

// Pop never reallocates the array to be smaller.
bool stackPop(stack *s, void *elementAddr) {
	//assert(!stackEmpty(s));
	if (!stackEmpty(s)) {
		s->logLength--;
		const void *sourceAddr = (const char *)s->elements + s->logLength * s->elementSize;
		memcpy(elementAddr, sourceAddr, s->elementSize);
		return true;
	}
	return false;
}

bool stackPeek(stack *s, void *elementAddr) {
	//assert(!stackEmpty(s));
	if (!stackEmpty(s)) {
		const void *sourceAddr = (const char *)s->elements + (s->logLength - 1) * s->elementSize;
		memcpy(elementAddr, sourceAddr, s->elementSize);
		return true;
	}
	return false;
}

void stackPrint(stack *s, void(*print)(int *), void *elementAddr) {
	if (!stackEmpty(s)) {
		for (int i = 0; i < s->logLength; i++) {
			const void *sourceAddr = (const char *)s->elements + i * s->elementSize;
			memcpy(elementAddr, sourceAddr, s->elementSize);
			(* print)(elementAddr);
		}
		puts("");
	}
}

int stackSize(stack *s) {
	if (s)
		return s->logLength;
	return 0;
}