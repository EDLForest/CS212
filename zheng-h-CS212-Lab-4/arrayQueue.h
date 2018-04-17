#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int   front;
	int	  back;
	int	  size;
	char* queue;
} Queue;


void queueInit(Queue* s);
int  push   (Queue* s, char c);
char pull	(Queue* s);
char front	(Queue* s);
bool isFull (Queue* s);

#endif
