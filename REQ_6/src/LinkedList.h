/*
 * LinkedList.h
 *
 *  Created on: Dec 19, 2019
 *      Author: eng-m
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
/*****INCLUDES*****************************************************/
#include <stdio.h>
#include <stdlib.h>

/*****DEFINES*****************************************************/
#define SUCCESS 0xFF
#define ERROR  	0

/*****TYPES*****************************************************/
typedef struct ST_node{
	int data;
	struct ST_node *next;
}ST_node;

typedef struct ST_list{
	ST_node *head;
	int listCapacity;
}ST_list;
/*****PROTOTYPES*****************************************************/
/*
 * Description: just create the head node and initialize the list capacity and head.
 * @param: *list -> pointer to the list structure to init. its values.
 * */
char createList(ST_list *list);
/*
 * Description: add new node to the chosen linked list
 * @param: *listHead -> pointer to the head of the chosen linked list.
 * @param: 	position -> the selected position to add the node to it starting from  ****ZERO****.
 * @param:  data -> the assigned data to the new node.
 */
void insertToList(ST_node *listHead, unsigned char position, int data);
/*
 * Description: delete node to the chosen linked list
 * @param: *listHead -> pointer to the head of the chosen linked list.
 * @param: 	position -> the selected position to delete the node from it starting from  ****ZERO****.
 * @param:  data -> the data of deleted node.
 */
void deleteFromList(ST_node *listHead, unsigned char position, int* data);

/*
 * Description: search for node in the chosen linked list.
 * @param: *listHead -> pointer to the head of the chosen linked list.
 * @param:  data -> the data of specified node.
 * @return: address of the desired node.
 */
ST_node* searchIntoList(ST_node *listHead, int data);

/*
 * Description: sort the chosen linked list by bubble sort.
 * @param: *listHead -> pointer to the head of the chosen linked list.
 */
void sortList(ST_node *listHead);	//Bonus
/*
 * Description: reverse the chosen linked list by bubble sort.
 * @param: *listHead -> pointer to the head of the chosen linked list.
 */
void reverseList(ST_node *listHead);	//Bonus


#endif /* LINKEDLIST_H_ */
