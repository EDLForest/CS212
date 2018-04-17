#include "tstdata.h"
#include "arrayStack.h"


int main(){
	
	//Initialie
	Stack* s;
	stackInit(s);
	
	printf("stack size = %d\n", STACKSZ);
	printf("Please input chars to be pushed into the stack\n");

	char input;
	while(true){
		scanf(" %c", &input);
		if(input == '^') {break;}
		
		if( isFull(s) ){
			printf("The stack is full. Enter the '^' character to stop.\n");
		}
		else{
			push(s, input);
		}
	}
	
	printf("Input ended, now printing the stack from top to bottom.\n");
	char output = 't';		//Temporary char
	while(output != '\0'){		//While the output pointer points a non Null value
		output = pop(s);
		printf("%c\n", output);
	}
	
	return 0;
}
