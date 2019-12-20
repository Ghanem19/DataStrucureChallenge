/*
 * LinkedList.c
 *
 *  Created on: Dec 19, 2019
 *      Author: eng-m
 */


#include "LinkedList.h"




extern ST_list list;
/*
 * Description: just create the head node and initialize the list capacity and head.
 * @param: *list -> pointer to the list structure to init. its values.
 * */

char createList(ST_list *list){
	list->head = (ST_node*) malloc(sizeof(ST_node));
	if(list->head == NULL){
		return ERROR;
	}
	list->listCapacity = 1;
	list->head->data = 0;
	list->head->next = NULL;

	return SUCCESS;
}

/*
 * Description: add new node to the chosen linked list
 * @param: *listHead -> pointer to the head of the chosen linked list.
 * @param: 	position -> the selected position to add the node to it starting from  ****ZERO****.
 * @param:  data -> the assigned data to the new node.
 */
void insertToList(ST_node *listHead, unsigned char position, int data){
	static char firstInsertion = 0;
	ST_node *st_newNode = NULL,*st_currentNode = listHead;

	st_newNode = (ST_node*)malloc(sizeof(ST_node));
	list.listCapacity++;
	if(position == 0){
    	 //insert in first and change head
		if(firstInsertion == 0){
			listHead->data = data;
			firstInsertion++;
			return;
		}
		else{
			st_newNode->next = listHead;
			st_newNode->data = data;
			list.head = st_newNode;
			//listHead = st_newNode;
			return;

		}
	}
	//after this loop currentNode would be the node before required position.
	while( (st_currentNode->next != NULL) && (--position) ){
		st_currentNode = st_currentNode->next;
	}
	st_newNode->data = data;
	st_newNode->next = st_currentNode->next;
	st_currentNode->next = st_newNode;
}

/*
 * Description: delete node to the chosen linked list
 * @param: *listHead -> pointer to the head of the chosen linked list.
 * @param: 	position -> the selected position to delete the node from it starting from  ****ZERO****.
 * @param:  data -> the data of deleted node.
 */
void deleteFromList(ST_node *listHead, unsigned char position, int* data){
	ST_node *deletedNode = NULL,*currentNode = listHead->next,*prevNode=listHead;
	if(listHead == NULL){
		return;
	}
	if(position == 0){
		deletedNode = listHead;
		list.head = listHead->next;
		free(deletedNode);
		return;
	}
	while(currentNode->next != NULL && (--position)){
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	prevNode->next = currentNode->next;
	*data = currentNode->data;
	free(currentNode);

}

/*
 * Description: search for node in the chosen linked list.
 * @param: *listHead -> pointer to the head of the chosen linked list.
 * @param:  data -> the data of specified node.
 * @return: address of the desired node.
 */
ST_node* searchIntoList(ST_node *listHead, int data){
	ST_node *currentNode = listHead;
	while(currentNode->next != NULL && currentNode->data != data){

		currentNode = currentNode->next;
		}


	return currentNode;
}

/*
 * Description: sort the chosen linked list by bubble sort.
 * @param: *listHead -> pointer to the head of the chosen linked list.
 */
void sortList(ST_node *listHead){
	//Bonus
	ST_node *innerLoop = listHead;
	int tempData,swapped = 1;

	while(swapped==1){
		swapped = 0;
		while(innerLoop->next != NULL){
			if(innerLoop->data > innerLoop->next->data){

				tempData = innerLoop->data;
				innerLoop->data = innerLoop->next->data;
				innerLoop->next->data = tempData;
				swapped = 1;
			}
			innerLoop = innerLoop->next;
		}

		innerLoop = listHead;

	}
}

/*
 * Description: reverse the chosen linked list by bubble sort.
 * @param: *listHead -> pointer to the head of the chosen linked list.
 */
void reverseList(ST_node *listHead){
	//Bonus
	ST_node *currentNode = listHead,*prevNode = NULL,*tempNode=NULL;

	while(currentNode != NULL){
		tempNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = tempNode;
	}

	list.head = prevNode;
}
