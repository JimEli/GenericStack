// Generic stack demonstration based upon code found here:
// https://see.stanford.edu/materials/icsppcs107/stack-implementation.pdf
//client.c
#include "stack.h"

// Function passed as parameter to stackPrint function.
void printElement(int *element) {
	printf("%d ", *element);
}

int main(int argc, char *argv[]) {
	int val;
	stack intStack;
	
	// Create a stack of integers.
	stackCreate(&intStack, sizeof(int));
	
	// Push 0 through 6 onto stack.
	for (val = 0; val < 6; val++)
		stackPush(&intStack, &val);

	// Demonstrate stack printing function.
	stackPrint(&intStack, printElement, &val);

	// Size, peek and pop elements from stack.
	while (!stackEmpty(&intStack)) {
		printf("Stack size: %d, ", stackSize(&intStack));
		stackPeek(&intStack, &val);
		printf("Peek at top element: %d, ", val);
		stackPop(&intStack, &val);
		printf("Popped: %d off stack\n", val);
	}

	// Destroy the stack.
	printf("Stack size: %d\n", stackSize(&intStack));
	stackDestroy(&intStack);

	while (getchar() != EOF); // Pause.
}
