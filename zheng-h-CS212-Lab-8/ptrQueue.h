#ifndef PTRQUEUE_H
#define PTRQUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	char data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct {
	struct Node* front;
	struct Node* back;
	struct Node* Anchor;
	struct Node* iterator;
	int posReturned;
} Queue;



void queueInit	(Queue* q);
int  push   	(Queue* q, char c);
char pull    	(Queue* q);
char pullBack	(Queue* q);
char front    	(Queue* q);
char back		(Queue* q);
int  isFull 	(Queue* q);

Node* getNext	(Queue* q, int direction);
Node* getCurrent(Queue* q);
void deleteCurrent(Queue* q);
void InsertAfter(Queue* q, char value);
Node* findValue	(Queue* q, char value);
void reset		(Queue* q, int direction);
int  Delete		(Queue* q, Node* target);

#endif
