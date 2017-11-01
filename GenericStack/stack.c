//stack.c
#include "stack.h"

bool stackCreate(Stack *stack, int elementSize) {
	//assert(elementSize > 0);
	if (elementSize > 0) {
		stack->elementSize = elementSize;
		stack->logLength = 0;
		stack->allocLength = kInitialAllocationSize;
		stack->elements = malloc(kInitialAllocationSize * elementSize);

		//assert(stack->elements != NULL);
		if (stack->elements != NULL)
			return true;
	}
	return false;
}

void stackDestroy(Stack *stack) {
	free(stack->elements);
}

bool stackEmpty(const Stack *stack) {
	return stack->logLength == 0;
}

// Push dynamically reallocates the array if needed to be larger.
bool stackPush(Stack *stack, const void *elementAddr) {
	if (stack->logLength == stack->allocLength) {
		stack->allocLength *= 2;
		stack->elements = realloc(stack->elements, stack->allocLength * stack->elementSize);
		//assert(stack->elems != NULL);
		if (stack->elements == NULL)
			return false;
	}
	void *destAddr = (char *)stack->elements + stack->logLength * stack->elementSize;
	memcpy(destAddr, elementAddr, stack->elementSize);
	stack->logLength++;
	return true;
}

// Pop never reallocates the array to be smaller.
bool stackPop(Stack *stack, void *elementAddr) {
	//assert(!stackEmpty(stack));
	if (!stackEmpty(stack)) {
		stack->logLength--;
		const void *sourceAddr = (const char *)stack->elements + stack->logLength * stack->elementSize;
		memcpy(elementAddr, sourceAddr, stack->elementSize);
		return true;
	}
	return false;
}

bool stackPeek(Stack *stack, void *elementAddr) {
	//assert(!stackEmpty(stack));
	if (!stackEmpty(stack)) {
		const void *sourceAddr = (const char *)stack->elements + (stack->logLength - 1) * stack->elementSize;
		memcpy(elementAddr, sourceAddr, stack->elementSize);
		return true;
	}
	return false;
}

void stackPrint(Stack *stack, void(*print)(int *), void *elementAddr) {
	if (!stackEmpty(stack)) {
		for (int i = 0; i < stack->logLength; i++) {
			const void *sourceAddr = (const char *)stack->elements + i * stack->elementSize;
			memcpy(elementAddr, sourceAddr, stack->elementSize);
			(* print)(elementAddr);
		}
		puts("");
	}
}

int stackSize(Stack *stack) {
	if (stack)
		return stack->logLength;
	return 0;
}
