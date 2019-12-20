/*
 * dynamicQueue.c
 *
 *  Created on: Dec 18, 2019
 *      Author: eng-m
 */

#include "dynamicQueue.h"
/*
 * Description: function create queue using dynamic array
 * @param: info -> pointer to structure to assign the queue pointer and capacity to it.
 * @param: size -> size of Queue;
 */

void createQueue(ST_queueInfo* info, int maxSize){
	info->queueCapacity = maxSize+1;
	info->queueBottomPointer = (int*)malloc((maxSize+1)*sizeof(int));
	*(info->queueBottomPointer) = EMPTY_QUEUE;
	printf("bottom = %d",*(info->queueBottomPointer));
	info->queueTopPointer = info->queueBottomPointer + maxSize;
	info->queuePointer = info->queueTopPointer;
}


/*
 * Description: set the given data at last first empty place in the queue.
 * @param: info -> pointer to queue that data would enqueue in it.
 * @param: data -> data to be enqueue.
 */
void enqueue(ST_queueInfo *info, int data){
	//add the data at the first location and -> queuePointer + 1
	*(info->queuePointer) = data;
	(info->queuePointer)--;


}

/*
 * Description: get out the first data the queue.
 * @param: info -> pointer to queue that data would dequeue from it.
 * @param: data -> data that dequeued assigned to that pointer.
 */
void dequeue(ST_queueInfo *info, int* data){
	//dequeue data from the top pointer then decrement the top by one.
	// realloc() function to remove the unused space
	*data = *(info->queueTopPointer);
	(info->queueTopPointer)--;
	(info->queueCapacity)--;
	info->queueBottomPointer = (int*)realloc(info->queueBottomPointer,(info->queueCapacity)*sizeof(int));

}

