/*
 * dataBase.h
 *
 *  Created on: Dec 20, 2019
 *      Author: eng-m
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "LinkedList.h"

#define MAX_DATABASE 100

int CreateDataBase(void);
void InsertToDataBase(int dbIndex,int data,unsigned char position);
void DeletefromtheDataBase(int dbIndex,int* data,unsigned char position);
ST_node* SearchintotheDataBase(int dbIndex,int data);
void SorttheDataBase(int dbIndex);


#endif /* DATABASE_H_ */
