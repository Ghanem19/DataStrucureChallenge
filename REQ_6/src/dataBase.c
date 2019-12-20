/*
 * dataBase.c
 *
 *  Created on: Dec 20, 2019
 *      Author: eng-m
 */

#include "dataBase.h"

ST_list listArray[MAX_DATABASE] = {0};
ST_list list = {0};
int dataBaseIndex = 0;

int CreateDataBase(void){
	printf("Creating a DataBase…..\n");
	dataBaseIndex++;
	createList(&listArray[dataBaseIndex]);
	printf("DataBase Created Successfully!!\n");
	printf("The number of DBs is %d.",dataBaseIndex);
	return dataBaseIndex;
}

void InsertToDataBase(int dbIndex,int data,unsigned char position){
	list = listArray[dbIndex];
	insertToList(list.head,position,data);
}
void DeletefromtheDataBase(int dbIndex,int* data,unsigned char position){
	list = listArray[dbIndex];
	deleteFromList(list.head,position,data);

}
ST_node* SearchintotheDataBase(int dbIndex,int data){
	list = listArray[dbIndex];
	return searchIntoList(list.head,data);
}
void SorttheDataBase(int dbIndex){
	list = listArray[dbIndex];
	sortList(list.head);
}

