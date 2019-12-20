/*
 ============================================================================
 Name        : REQ_4.c
 Author      : Ghanem
 Version     :
 Copyright   : 
 Description : Expression evaluation.
 ============================================================================
 */

#include "expressionEvaluation.h"

int main(void) {

	char str []= "10+12*6/2";

	// didn't cover the parenthesis cases.
	printf("result = %d",evaluate(str));


	return EXIT_SUCCESS;
}
