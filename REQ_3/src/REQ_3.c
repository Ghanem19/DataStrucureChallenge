/*
 ============================================================================
 Name        : REQ_3.c
 Author      : Ghanem
 Version     :
 Copyright   : 
 Description : Queue implementation using dynamic array.
 ============================================================================
 */


#include "dynamicQueue.h"
int main(void) {
	ST_queueInfo queue = {0};
	 createQueue(&queue,3);
	enqueue(&queue,1);
	enqueue(&queue,2);
	enqueue(&queue,3);

	return EXIT_SUCCESS;
}
