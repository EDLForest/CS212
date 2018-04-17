#include <stdlib.h>
#include <stdio.h>
#include "tstdata.h"
#include "ptrQueue.h"


void printList(Queue* q){
	// char output = 't';
	//reset the iterator to print the contents
	reset(q,0);
	do {//While the output pointer points a non Null value
		output = getCurrent(q)->data;
		printf("%c", output);
		if(!getNext(q,1)) break;
	} while(output != '\0');

	printf("\n");
	//reset iterator after printing
	reset(q, 0);
}

int main(){

	//Initialize
	Queue* q = (Queue*)malloc(sizeof(Queue));
	queueInit(q);
	char thirdChar = '\0';
	int counter = 0;

	printf("Please input chars to be pushed into the queue\n");
	char input;
	while(1){
		scanf(" %c", &input);
		if(input == '^') break;

		counter++;
		if(counter == 3) thirdChar = input;

		if( isFull(q) == 1 ){
			printf("The queue is full. Enter the '^' character to stop.\n");
		}
		else{
			push(q, input);
		}
	}

	printf("Input ended, now printing the queue from front to back.\n");
	char output = 't';
	printList(q);
	// do {				//While the output pointer points a non Null value
	// 	//printf("out put is: %c\n", output);
	// 	output = getCurrent(q)->data;
	// 	printf("%c", output);
	// 	if(!getNext(q,1)) break;
	// } while(output != '\0');
	printf("\nthe third character inputted was %c\n", thirdChar);

	//if the third character is not NULL
	if(thirdChar){

		//Find the first Occurance of the third Character
		Node* findResult = findValue(q, thirdChar);

		//While we are not at that character yet, getNext
		//There is atleast one such character in the List
		printf("The character %c was found at position %d.\n", thirdChar, q->posReturned);

		//While we have not reached the third character, getNext
		while (getCurrent(q)->data != thirdChar){ getNext(q,1); }
		//After we have located the Node, insert '*' after it
		//then delete the currentNode
		InsertAfter(q, '*');
		Delete(q, findResult);
		printList(q);
		//reset the iterator to print the contents
		// reset(q,0);
		// do {//While the output pointer points a non Null value
		// 	output = getCurrent(q)->data;
		// 	printf("%c", output);
		// 	if(!getNext(q,1)) break;
		// } while(output != '\0');
        //
		// printf("\n");
		// //reset iterator after printing
		// reset(q, 0);

		//While there are still copies of third character left, delete them
		while( (findResult = findValue(q, thirdChar)) ){
			while (getCurrent(q)->data != thirdChar){ getNext(q,1); }
			printf("The character %c was found at position %d.\n", thirdChar, q->posReturned);
			InsertAfter(q, '*');
			Delete(q, findResult);
		}
		printList(q);

	}



    //
	// printf("To enter Testing console, enter t\n");
	// printf("To exit, enter otherwise");
	// scanf(" %c", &input);
	// if(input == 't')
	// 	Test_console(q);


	return 0;
}
