#include "tstdata.h"
#include "arrayQueue.h"


/**
*This function is used to declare and initialize a new Queue.
*@Parameter: Queue* q:		The poinyer to the queue
*/
void queueInit(Queue* q){
	q->front = 0;
	q->back	 = 0;
	q->size  = 0;
	q->queue = (char*) malloc( (QUEUESZ+1) * sizeof(char) );
	q->queue[QUEUESZ] = '\0';
}

/**
*This function is used to add/push new elements into the queue
*The element is added to the end of the array and the back index
*will increase. when size = QUEUESZ-1, no more push is allowed
*until an item has been dequeued.
*@Parameter:	Queue* q:		The pointer to the queue
*				char c:			the character that will be push into the queue
*
*@return: int 	return a 0 if the push was successful
*				return a -1 if the push was unsuccessful
*/
int push(Queue* q, char c){
	if(isFull(q)){
		return -1;
	}
	q->queue[(q->back)] = c;
	q->back = (q->back+1) % QUEUESZ;
	q->size++;

	return 0;
}

/**
*This function is used to obtain the front elements from the queue.
*When pull is called, the front element will be removed and returned,
*The size of the queue will decrement. If the size is at 0, return Null.
*@Parameter:	Queue* q:		The pointer to the queue
*
*@return: char 	return the top char of the queue
*				return NULL if the queue is empty
*/
char pull(Queue* q){
	if(q->size == 0){
		printf("Queue is empty");
		return '\0';
	}
	char val =  q->queue[(q->front)];
	q->front = (q->front+1) % QUEUESZ;
	q->size--;

	return val;
}

/**
*This function is used to obtain the front elements from the queue
*The front element will not be removed after this function is called.
*If the queue is empty, return Null.
*@Parameter:	Queue* q:		The pointer to the queue
*
*@return:		char 	return the top char of the queue
*						return NULL if the queue is empty
*/
char front(Queue* q){
	if(q->size == 0){
		printf("Queue is empty");
		return '\0';
	}
	return q->queue[q->front];
}

/**
*This function return a boolean indicating whether or not the queue is full
*@Parameter: Queue* q:		The pointer to the queue
*
*@return:	bool	true  if the queue is full
*					false if the queue is not full
*/
bool isFull(Queue* q){
	return (q->size == QUEUESZ);
}
