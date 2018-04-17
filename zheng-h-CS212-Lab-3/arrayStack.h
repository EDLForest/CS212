#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int   top;
	char* stack;
} Stack;


void stackInit(Stack* s);
int  push   (Stack* s, char c);
char pop    (Stack* s);
char top    (Stack* s);
bool isFull (Stack* s);

#endif
