// Stack demonstration based upon code found here:
//  https://see.stanford.edu/materials/icsppcs107/stack-implementation.pdf
//client.c
#include "stack.h"

// Function passed as parameter to stackPrint function.
void printElement(int *element) {
	printf("%d ", *element);
}

int main(int argc, char *argv[]) {
	int val;
	stack intStack;
	
	stackCreate(&intStack, sizeof(int));
	
	for (val = 0; val < 6; val++)
		stackPush(&intStack, &val);

	// Stack print function.
	stackPrint(&intStack, printElement, &val);

	while (!stackEmpty(&intStack)) {
		printf("Stack size: %d, ", stackSize(&intStack));
		stackPeek(&intStack, &val);
		printf("Peek at top element: %d, ", val);
		stackPop(&intStack, &val);
		printf("Popped: %d off stack\n", val);
	}

	printf("Stack size: %d\n", stackSize(&intStack));

	stackDestroy(&intStack);

	while (getchar() != EOF);
}

