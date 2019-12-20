/*
 ============================================================================
 Name        : REQ_2.c
 Author      : Ghanem 
 Description : Stack usage to find balance of parentheses.
 ============================================================================
 */
#include "checkBalance.h"
int main(void) {
	ST_stackInfo stacks = {0};

	createStack(&stacks,10);
	char str[] = "((((";
	printf("%x",checkForBalancedParantheses(str));
	return EXIT_SUCCESS;
}
