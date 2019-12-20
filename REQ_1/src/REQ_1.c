/*
 ============================================================================
 Author      : Ghanem
 Description : Stack Implementation using dynamic array.
 ============================================================================
 */
#include "dynamicStack.h"

#define BALANCED 0xff
#define UNBALANCED 0

int main(void) {
	ST_stackInfo stacks = {0};

	createStack(&stacks,10);
	push(&stacks,1);
	int x;
	pop(&stacks,&x);
	return EXIT_SUCCESS;
}
