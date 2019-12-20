/*
 ============================================================================
 Name        : REQ_6.c
 Author      : Ghanem
 Version     :
 Copyright   : 
 Description : Data Base Application.
 ============================================================================
 */

#include "database.h"
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int numOfqueries = 0,queries = 0,index=0,position,data,loops = 10;
	ST_node *foundedNode = NULL;
	do{
	printf("Please Enter Number of Queries\n");
	scanf("%d",&numOfqueries);
	printf("Please choose the queries:\n");
	printf(" 1- Create DataBase.\n 2- Insert to DataBase.\n 3- Delete from the DataBase.\n");
	printf(" 4- Search into the DataBase.\n 5- Sort the DataBase.\n 6- Operation on two nodes.\n");
	printf("Waiting for your response….");
	while(numOfqueries--){
		scanf("%d",&queries);
		switch(queries){
			case 1:
				CreateDataBase();
				break;
			case 2:
				printf("Please Select DB to insert into:\n");
				scanf("%d",&index);
				printf("Please Enter Data to insert:\n");
				scanf("%d",&data);
				printf("Please enter the position to insert into:\n");
				scanf("%d",&position);
				InsertToDataBase(index,data,position);
				printf("Data Inserted successfully!!\n");
				break;
			case 3:
				printf("Please Select DB to delete from:\n");
				scanf("%d",&index);
				printf("Please enter the position to be deleted:\n");
				scanf("%d",&position);
				DeletefromtheDataBase(index,&data,position);
				break;
			case 4:
				printf("Please Select DB to search in:\n");
				scanf("%d",&index);
				printf("Please Enter Data to search fo:\n");
				scanf("%d",&data);
				foundedNode = SearchintotheDataBase(index,data);
				break;
			case 5:
				printf("Please Select DB to be sorted:\n");
				scanf("%d",&index);
				SorttheDataBase(index);
				break;
			case 6:

				break;
			default:
				break;
		}



	}
	}while(loops--);
	return EXIT_SUCCESS;
}
