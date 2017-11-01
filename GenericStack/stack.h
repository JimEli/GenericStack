//stack.h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#ifndef _Stack_H_
#define _Stack_H_

struct Stack_ {
	void *elements;
	int elementSize;
	int logLength;
	int allocLength;
};

typedef struct Stack_ Stack;

#define kInitialAllocationSize 4 

bool stackCreate(Stack *, int);
void stackDestroy(Stack *);
bool stackEmpty(const Stack *);
bool stackPush(Stack *, const void *);
bool stackPop(Stack *, void *);
bool stackPeek(Stack *, void *);
int stackSize(Stack *);
void stackPrint(Stack *, void(*print)(int *), void *);

#endif
