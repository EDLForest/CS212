#include "tstdata.h"
#include "ptrQueue.h"


/**
*This function is used to initialize a new Queue.
*@Parameter Queue*		pointer to a Queue
*/
void queueInit(Queue* q){
	//Define a NULL pointer, anchor, for the new queue
	Node* anchor = NULL;
	//Put the anchor at the bottom of an empty stack
	q->front = anchor;
	q->back = anchor;
}

/**
*This function is used to add/push new elements into the queue
*The next of current back pointer will point to the new node pushed into
*the queue, then this new Node will become the new back of the queue
*@Parameter:	Queue* q:		The pointer to the queue
*				char c:			the character that will be push into the queue
*
*@return: int 	return a 0 if the push was successful
*				return a -1 if the push was unsuccessful, queue is full
*/
int push(Queue* q, char c){
	//If the queue is full, return -1
	if(isFull(q) == 1)	return -1;

	//Allocate an empty node
	Node* aNode = (Node*) malloc( sizeof(Node) );
	//Assign c to the data of the new Node
	aNode->data = c;

	if(isFull(q) == -1){
		//if the queue is empty,
		//set both the front and back of the queue as the new node
		q->back = aNode;
		q->front = aNode;
	}
	else{
		//If the queue is neither full or empty
		//Current back->next now points to aNode
		//then aNode becomes the new back of the queue
		q->back->next = aNode;
		q->back = aNode;
	}
	return 0;
}

/**
*This function is used to obtain the front element from the queue.
*After returning the value of the current front Node, current front Node will be
*removed from the stack and its next node will become the new front Node
*
*@Parameter:	Queue* q:		The pointer to the queue
*
*@return: char 	return the front char of the queue
*				return NULL if the queue is empty
*/
char pull(Queue* q){
	if( isFull(q) == -1 ){
		printf("Queue is empty");
		return '\0';
	}
	//Save the urrent top Node to a temp variable
	Node temp = *q->front;
	//Free the adress the current top pointer points to
	free(q->front);
	//Set the new top Node as the next Node of the current top Node
	q->front = temp.next;

	return temp.data;
}

/**
*This function is used to obtain the front elements from the queue
*The queue will not be affected by this function
*@Parameter:	Queue* q:		The pointer to the queue
*
*@return:	char 	return the front char of the queue
*					return NULL if the queue is empty
*/
char front(Queue* q){
	if(isFull(q) == -1){
		printf("Queue is empty");
		return '\0';
	}
	return q->front->data;
}

/**
*This function return a boolean indicating whether or not the queue is full
*@Parameter: Queue* q:		The pointer to the queue
*
*@return:	int		-1 if the queue is empty
*					1 if the queue is isFull
					0 otherwise
*/
int isFull(Queue* q){
	if(q->front == NULL)	return -1;

	Node* p = NULL;
	if( ( p = malloc(sizeof(Node)) ) == NULL ){
		free(p);
		return 1;
	}
	else{
		free(p);
		return 0;
	}
}
