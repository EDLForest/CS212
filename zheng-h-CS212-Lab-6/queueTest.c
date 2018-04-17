#include "tstdata.h"
#include "ptrQueue.h"
#include "userTest.h"

int main(){

	//Initialize
	Queue* q;
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
	char output = ' ';
	do {				//While the output pointer points a non Null value
		output = pull(q);
		printf("%c\n", output);
	} while(output != '\0');

	printf("To enter Testing console, enter t\n");
	printf("To exit, enter otherwise");
	scanf(" %c", &input);
	if(input == 't')
	Test_console(q);


	return 0;
}
