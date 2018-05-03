#include <stdlib.h>
#include <stdio.h>
#include "tstdata.h"
#include "ptrQueue.h"


int main(){

	//Initialize
	Queue* q = (Queue*)malloc(sizeof(Queue));
	queueInit(q);

	printf("Please input chars to be pushed into the queue\n");
	char input;
	while(1){
		scanf(" %c", &input);
		if(input == '^') break;

		if( isFull(q) == 1 ){
			printf("The queue is full. Enter the '^' character to stop.\n");
		}
		else{
			push(q, input);
		}
	}

	printf("Input ended, now printing the queue from front to back.\n");
	reset(q, 0);
	Node* current = getCurrent(q);
	char output = ' ';
	do {				//While the output is a non Null value
		//printf("out put is: %c\n", output);
		output = current->data;
		current = getNext(q,1);
		printf("%c", output);
	} while(current);

	printf("\n");

	printf("Now printing the queue from back to front.\n");
	reset(q, 1);
	current = getCurrent(q);
	output = ' ';
	do {				//While the output is a non Null value
		//printf("out put is: %c\n", output);
		output = current->data;
		printf("%c", output);
		current = getNext(q,0);
	} while(current);

	printf("\n");


	// printf("To enter Testing console, enter t\n");
	// printf("To exit, enter otherwise");
	// scanf(" %c", &input);
	// if(input == 't')
	// 	Test_console(q);


	return 0;
}
