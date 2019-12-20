/*
 * dynamicQueue.h
 *
 *  Created on: Dec 18, 2019
 *      Author: eng-m
 */

#ifndef DYNAMICQUEUE_H_
#define DYNAMICQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_QUEUE '#'

typedef struct ST_queueInfo{
	int *queueTopPointer;
	int *queueBottomPointer;
	int *queuePointer;
	int queueCapacity;

}ST_queueInfo;

/*
 * Description: function create queue using dynamic array
 * @param: info -> pointer to structure to assign the queue pointer and capacity to it.
 * @param: size -> size of Queue;
 */
void createQueue(ST_queueInfo* info, int maxSize);
/*
 * Description: set the given data at last first empty place in the queue.
 * @param: info -> pointer to queue that data would enqueue in it.
 * @param: data -> data to be enqueue.
 */
void enqueue(ST_queueInfo *info, int data);
/*
 * Description: get out the first data the queue.
 * @param: info -> pointer to queue that data would dequeue from it.
 * @param: data -> data that dequeued assigned to that pointer.
 */

void dequeue(ST_queueInfo *info, int* data);

#endif /* DYNAMICQUEUE_H_ */
