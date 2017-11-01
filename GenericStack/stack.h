//stack.h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#ifndef _STACK_H_
#define _STACK_H_

typedef struct {
	void *elements;
	int elementSize;
	int logLength;
	int allocLength;
} stack;

void stackCreate(stack *, int);
void stackDestroy(stack *);
bool stackEmpty(const stack *);
bool stackPush(stack *, const void *);
bool stackPop(stack *, void *);
bool stackPeek(stack *, void *);
int stackSize(stack *);
void stackPrint(stack *, void(*print)(int *), void *);

#define kInitialAllocationSize 4 

#endif
