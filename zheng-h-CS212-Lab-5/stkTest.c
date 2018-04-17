#include "tstdata.h"
#include "ptrStack.h"

int main(){

	//Initialize
	Stack* s;
	stackInit(s);

	printf("Please input chars to be pushed into the stack\n");
	char input;
	while(1){
		scanf(" %c", &input);
		if(input == '^') break;

		if( isFull(s) == 1 ){
			printf("The stack is full. Enter the '^' character to stop.\n");
		}
		else{
			push(s, input);
		}
	}

	printf("Input ended, now printing the stack from top to bottom.\n");
	char output = ' ';
	do {				//While the output pointer points a non Null value
		output = pop(s);
		printf("%c\n", output);
	} while(output != '\0');
    //
	// printf("To enter Testing console, enter t\n");
	// printf("To exit, enter otherwise");
	// scanf(" %c", &input);
	// if(input == 't')
	// 	Test_console(s);


	return 0;
}
