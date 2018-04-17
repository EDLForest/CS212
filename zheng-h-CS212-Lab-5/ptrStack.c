#include "tstdata.h"
#include "ptrStack.h"


/**
*This function is used to initialize a new stack.
*@Parameter Stack*		pointer to a Stack
*/
void stackInit(Stack* s){
	//Define a NULL pointer, anchor, for the new stack
	Node* anchor = NULL;
	//Put the anchor at the bottom of an empty stack
	s->top = anchor;
}

/**
*This function is used to add/push new elements into the stack
*The new Node will have its pointer points to the current top Node
*in the stack, then this new Node will become the top of the stack
*@Parameter:	Stack* s:		The pointer to the stack
*				char c:			the character that will be push into the stack
*
*@return: int 	return a 0 if the push was successful
*				return a -1 if the push was unsuccessful
*/
int push(Stack* s, char c){
	if(isFull(s) == 1)return -1;
	//Create an empty node
	//might need to check for memory full
	Node* aNode = (Node*) malloc( sizeof(Node) );
	//Assign c to the data of the new Node
	//Assign the current top of the stack as the next Node of the new Node
	aNode->data = c;
	aNode->next = s->top;
	//Set the new Node as the top node of the Stack
	s->top = aNode;
	return 0;
}

/**
*This function is used to obtain the top elements from the stack.
*After returning the value of the top Node, this top Node will be
*removed from the stack and the next node will become the new top Node
*
*@Parameter:	Stack* s:		The pointer to the stack
*
*@return: char 	return the top char of the stack
*				return NULL if the stack is empty
*/
char pop(Stack* s){
	if( isFull(s) == -1 ){
		printf("Stack is empty");
		return '\0';
	}
	//Save the urrent top Node to a temp variable
	Node temp = *s->top;
	//Free the adress which the current top pointer points to
	free(s->top);
	//Set the next Node of the current top Node as the new top Node
	s->top = temp.next;

	return temp.data;
}

/**
*This function is used to obtain the top elements from the stack
*The Stack will not be affected by this function
*@Parameter:	Stack* s:		The pointer to the stack
*
*@return:	char 	return the top char of the stack
*					return NULL if the stack is empty
*/
char top(Stack* s){
	if(isFull(s) == -1){
		printf("Stack is empty");
		return '\0';
	}
	return s->top->data;
}

/**
*This function return a boolean indicating whether or not the stack is full
*@Parameter: Stack* s:		The pointer to the stack
*
*@return:	bool	true  if the stack is full
*					false if the stack is not full
*/
int isFull(Stack* s){
	if(s->top == NULL)
		return -1;
	else if( malloc(sizeof(Node)) == NULL )
		return 1;
	else
		return 0;
}
