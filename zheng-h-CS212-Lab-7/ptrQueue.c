#include <stdlib.h>
#include <stdio.h>
#include "tstdata.h"
#include "ptrQueue.h"



void queueInit	(Queue* q){
	//Define an anchor node, for the new queue
	q->Anchor = (Node*)malloc(sizeof(Node));
	//an empty queue have both front and back pointing to Anchor
	q->front = q->Anchor;
	q->back = q->Anchor;
	q->iterator = q->Anchor;
}

int  push   	(Queue* q, char c){
	//if the queue is full, return -1
	if( isFull(q) == 1)	return -1;


	//allocate a new Node
	Node* aNode = (Node*) malloc(sizeof(Node));
	aNode-> data = c;
	//if the queue is empty, the front and back should both points to
	//the newly created Node. the nextNode of the new Node points to anchor
	//And the prev Node of Anchor points to the new node.
	//also the iterator should also points to the newNode
	if(isFull(q) == -1){
		q->back = aNode;
		q->front = aNode;
		q->iterator = aNode;

		q->Anchor->prev = aNode;
		aNode->next = q->Anchor;
	}
	//Else, set the nextNode of the back node points to the new node
	//the prevNode of the new Node points to the back
	//then set the nextNode of the new Node points to the Anchor
	//then set the prevNode of the anchor as the newNode
	//then set the new Node as the back of the queue
	else{
		q->back->next = aNode;
		aNode->prev = q->back;
		aNode->next = q->Anchor;
		q->Anchor->prev = aNode;
		q->back = aNode;
	}

	return 0;
}


char pull    	(Queue* q){
		if( isFull(q) == -1 ){			//if the queue is empty return null
			printf("Queue is empty");
			return '\0';
		}
		//else if the front is the same as the back, which
		//means that this is the last node of the queue
		else if(q->front == q->back){
			Node temp = *(q->front);	//Save the current fornt Node
			free(q->front);				//Free the current front
			q->front = q->Anchor;
			q->back  = q->Anchor;
			q->iterator = q->Anchor;
			return temp.data;
		}
		else{	//Otherwise
			//move the iterator to the nextNode if it points to the front
			if (q->iterator == q->front)
				getNext(q, 0);
			//Save the Current front Node to a temp variable
			Node temp = *(q->front);
			//Free the adress the current front pointer points to
			free(q->front);
			//Set the new front Node as the next Node of the current front Node
			q->front = temp.next;

			return temp.data;
		}
}

char pullBack	(Queue* q){
	if (isFull(q) == -1){
		printf("Queue is empty");
		return '\0';
	}
	//else if the front is the same as the back, which
	//means that this is the last node of the queue
	else if(q->front == q->back){
		Node temp = *(q->back);	//Save the current back Node
		free(q->back);				//Free the current back
		q->front = q->Anchor;
		q->back  = q->Anchor;
		q->iterator = q->Anchor;
		return temp.data;
	}
	else{	//Otherwise
		//if the iterator is at the back
		//move it to the previousNode
		if (q->iterator == q->back)
			getNext(q, 1);
		//Save the Current back Node to a temp variable
		Node temp = *(q->back);
		//Free the address the current back pointer points to
		free(q->back);
		//Set the new back Node as the next Node of the current back node
		q->Anchor->prev = temp.prev;
		q->back = temp.prev;
		//Set the next node of the new back node to the Anchor
		q->back->next = q->Anchor;


		return temp.data;
	}


}


char front    	(Queue* q){
	if(isFull(q) == -1){
		printf("Queue is empty");
		return '\0';
	}
	return q->front->data;
}

char back(Queue* q){
	if(isFull(q) == -1){
		printf("Queue is empty");
		return '\0';
	}
	return q->back->data;
}

int isFull 		(Queue* q){
	//If the front and/or back is equals to the Anchor of the Queue
	//The queue is empty
	if(q->front == q->Anchor)	return -1;

	//If malloc return Null, then the queue is full
	Node* p;
	if( ( p = malloc(sizeof(Node)) ) == NULL ){
		free(p);
		return 1;
	}
	else{
		free(p);
		return 0;
	}
}


Node* getNext(Queue* q, int direction){
	if (direction == 1){
		if(q->iterator == q->back){
			return NULL;
		}
		else{
			q->iterator = q->iterator->next;
			return getCurrent(q);
		}
	}
	else if(direction == 0){
		if(q->iterator == q->front){
			return NULL;
		}
		else{
			q->iterator = q->iterator->prev;
			return getCurrent(q);
		}
	}
	else{	//invalid direction
		return NULL;
	}
}

Node* getCurrent (Queue* q){
	if (isFull(q) == -1)	return NULL;
	else	return q->iterator;
}

void reset (Queue* q, int direction){
	if (direction == 0)
		q->iterator = q-> front;
	else
		q->iterator = q-> back;
}

int Delete (Queue* q, Node* target){
	//If the queue is empty, then there is nothing to Delete
	//return 0
	if(isFull(q) == -1)
		return 0;
	//Else if there is only one element in the queue
	//If the target is the same as the back, front and the iterator
	//delete the node
	else if(q->front == q->back)
		if (target == q->back){
			free(q->back);
			q->front = q->Anchor;
			q->back = q->Anchor;
			q->iterator = q->Anchor;
			return 1;
		}
		else
			return 0;
	else{
		//Start from the front node of the queue
		//Loop until we reached the Anchor of the queue
		Node* current = q->front;
		while (current != q->Anchor){
			//if the current pointer and the target pointer
			//points to the same node, delete that node
			if(current == target){
				//If the target node is pointed at by the iterator
				//set the iterator to the nextNode, if that's
				//not possible, set the iterator as the previousNode
				//since here we assume that the list is non empty
				//and contain at least 2 nodes, we do not need to
				//worry about both cases of getNext failing
				if(current == q->iterator){
					if(!getNext(q, 0))
						getNext(q, 1);
				}
				if(current == q->front){
					Node temp = *(current);
					free(current);
					q->front = temp.next;
					// temp->next = temp;
				}
				else if(current == q->back){
					Node temp = *(current);
					free(current);
					q->back = temp.prev;
					q->back->next = q->Anchor;
					q->Anchor->prev = q->back;
				}
				else{
					Node temp = *current;
					free(current);
					//previousNode's nextNode points to the nextNode of currentNode
					temp.prev->next = temp.next;
					//nextNode's previousNode points to the previousNode of currentNode
					temp.next->prev = temp.prev;
				}

				return 1;
			}

			//set the currentNode to the previous node in the queue
			current = current->next;
		}
	}
	return 0;
}


































//
//
//
//
//
//
//
//
// /**
// *This function is used to initialize a new Queue.
// *@Parameter Queue*		pointer to a Queue
// */
// void queueInit(Queue* q){
// 	//Define a NULL pointer, anchor, for the new queue
// 	Node* anchor = NULL;
// 	//an empty queue have both front and back pointing to Anchor
// 	q->front = anchor;
// 	q->back = anchor;
// }
//
// /**
// *This function is used to add/push new elements into the queue
// *The next of current back pointer will point to the new node pushed into
// *the queue, then this new Node will become the new back of the queue
// *@Parameter:	Queue* q:		The pointer to the queue
// *				char c:			the character that will be push into the queue
// *
// *@return: int 	return a 0 if the push was successful
// *				return a -1 if the push was unsuccessful, queue is full
// */
// int push(Queue* q, char c){
// 	//If the queue is full, return -1
// 	if(isFull(q) == 1)	return -1;
//
// 	//Allocate an empty node
// 	Node* aNode = (Node*) malloc( sizeof(Node) );
// 	//Assign c to the data of the new Node
// 	aNode->data = c;
//
// 	if(isFull(q) == -1){
// 		//if the queue is empty,
// 		//set both the front and back of the queue as the new node
// 		q->back = aNode;
// 		q->front = aNode;
// 	}
// 	else{
// 		//If the queue is neither full or empty
// 		//aNode points to what the back node points to
// 		//Current back->next now points to aNode
// 		//Prev of aNode points to
// 		//then aNode becomes the new back of the queue
// 		aNode.next = q->back->next;
// 		q->back->next = aNode;
// 		aNode.prev = q->back;
// 		q->back = aNode;
// 	}
// 	return 0;
// }
//
// /**
// *This function is used to obtain the front element from the queue.
// *After returning the value of the current front Node, current front Node will be
// *removed from the queue and its next node will become the new front Node
// *
// *@Parameter:	Queue* q:		The pointer to the queue
// *
// *@return: char 	return the front char of the queue
// *				return NULL if the queue is empty
// */
// char pull(Queue* q){
// 	if( isFull(q) == -1 ){
// 		printf("Queue is empty");
// 		return '\0';
// 	}
// 	//Save the Current top Node to a temp variable
// 	Node temp = *(q->front);
// 	//Free the adress the current top pointer points to
// 	free(q->front);
// 	//Set the new top Node as the next Node of the current top Node
// 	q->front = temp.next;
//
// 	return temp.data;
// }
//
// /**
// *This function is used to obtain the front elements from the queue
// *The queue will not be affected by this function
// *@Parameter:	Queue* q:		The pointer to the queue
// *
// *@return:	char 	return the front char of the queue
// *					return NULL if the queue is empty
// */
// char front(Queue* q){
// 	if(isFull(q) == -1){
// 		printf("Queue is empty");
// 		return '\0';
// 	}
// 	return q->front->data;
// }
//
// /**
// *This function return a boolean indicating whether or not the queue is full
// *@Parameter: Queue* q:		The pointer to the queue
// *
// *@return:	int		-1 if the queue is empty
// *					1 if the queue is isFull
// 					0 otherwise
// */
// int isFull(Queue* q){
// 	if(q->front == NULL)	return -1;
//
// 	Node* p = NULL;
// 	if( ( p = malloc(sizeof(Node)) ) == NULL ){
// 		free(p);
// 		return 1;
// 	}
// 	else{
// 		free(p);
// 		return 0;
// 	}
// }
