#ifndef PTRQUEUE_H
#define PTRQUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	char data;
	struct Node* next;
} Node;

typedef struct {
	struct Node* front;
	struct Node* back;
} Queue;



void queueInit	(Queue* q);
int  push   	(Queue* q, char c);
char pull    	(Queue* q);
char front    	(Queue* q);
int isFull 		(Queue* q);

#endif
