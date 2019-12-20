/*
 ============================================================================
 Name        : REQ_5.c
 Author      : Ghanem
 Version     :
 Copyright   : 
 Description : Linked List.
 ============================================================================
 */

#include "LinkedList.h"
ST_list list = {0};
int main(void) {

	createList(&list);
	insertToList(list.head,0,5);
	insertToList(list.head,1,4);
	insertToList(list.head,2,3);
	insertToList(list.head,3,2);
	insertToList(list.head,4,1);
	insertToList(list.head,5,0);


	sortList(list.head);

	reverseList(list.head);

	return EXIT_SUCCESS;
}
