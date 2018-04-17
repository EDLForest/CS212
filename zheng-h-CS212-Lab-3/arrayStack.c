#include "tstdata.h"
#include "arrayStack.h"


/**
*This function is used to declare and initialize a new stack.
*@return:	Stack*s		return a pointer to the newly created stack
*/
void stackInit(Stack* s){
	s->top = -1;
	s->stack = (char*) malloc( (STACKSZ+1) * sizeof(char) );
	s->stack[STACKSZ] = '\0';
}

/**
*This function is used to add/push new elements into the stack
*The element is added to the array and its index will become thenew topPos
*@Parameter:	Stack* s:		The pointer to the stack 
*				char c:			the character that will be push into the stack
*
*@return: int 	return a 0 if the push was successful
*				return a -1if the push was unsuccessful
*/
int push(Stack* s, char c){
	if(isFull(s)){ //if the topPos is at STACKSZ-1 already, stack is full
		return -1;
	}
	s->stack[++(s->top)] = c;
	return 0;
}

/**
*This function is used to obtain the top elements from the stack.
*After poopping it, the top element will be removed and returned from the stack
*The function dosen't actually clears the top char when popping, the
*top index will be move down and when new char is pushed
*into the stack, the old values will be overwritten.
*
*@Parameter:	Stack* s:		The pointer to the stack 
*				int* topPos:	the pointer to the top position at the stack
*								a topPos of -1 means the stack is empty
*
*@return: char 	return the top char of the stack
*				return NULL if the stack is empty
*/
char pop(Stack* s){
	if(s->top == -1){
		printf("Stack is empty");
		return '\0';
	}
	return s->stack[(s->top)--];
}

/**
*This function is used to obtain the top elements from the stack
*The topPos is uneffected by this method
*@Parameter:	Stack* s:		The pointer to the stack 
*				int* topPos:	the pointer to the top position at the stack
*								a topPos of -1 means the stack is empty
*
*@return:	char 	return the top char of the stack
*					return NULL if the stack is empty
*/
char top(Stack* s){
	if(s->top == -1){
		printf("Stack is empty");
		return '\0';
	}
	return s->stack[s->top];
}

/**
*This function return a boolean indicating whether or not the stack is full
*@Parameter: Stack* s:		The pointer to the stack
*
*@return:	bool	true  if the stack is full
*					false if the stack is not full
*/
bool isFull(Stack* s){
	return (s->top + 1 == STACKSZ);
}

