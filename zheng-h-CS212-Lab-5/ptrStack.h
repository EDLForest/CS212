#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	char data;
	struct Node* next;
} Node;

typedef struct {
	struct Node* top;
} Stack;



void stackInit	(Stack* s);
int  push   	(Stack* s, char c);
char pop    	(Stack* s);
char top    	(Stack* s);
int isFull 		(Stack* s);

#endif
