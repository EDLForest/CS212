#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <map>
#include "tstdata.h"
#include "List.h"
#include "queue.h"
#include "stack.h"

Queue<char>* infixToPostFix(Queue<char>* inputQueue);
int evaluatePostFix(Queue<char>* postfixQueue);
int evaluateHelper(int a, int b, char op);

//Global Variables
//defining a digit map to map the char digit to int
map<char, int> digitMap;
//opMap provides easy lookup for precedence
map<char, int> opMap;

using namespace std;
int main(){
    Queue<char> inputQueue;
    //Take in input from stdin
    //Store the inputed character sequence into a queue
    printf("Please input chars to be pushed into the queue\n");
	char input;
	while(1){
		scanf(" %c", &input);
		if(input == '^') break;

		if( inputQueue.isFull() == 1 ){
			printf("The queue is full. Enter the '^' character to stop.\n");
		}
		else{
			inputQueue.push(input);
		}
	}
    //Print the Queue
	cout << "Printing the inputQueue fron front to back" << endl;
    inputQueue.printList();


	//Initializating maps
	digitMap['0'] = 0;
	digitMap['1'] = 1;
	digitMap['2'] = 2;
	digitMap['3'] = 3;
	digitMap['4'] = 4;
	digitMap['5'] = 5;
	digitMap['6'] = 6;
	digitMap['7'] = 7;
	digitMap['8'] = 8;
	digitMap['9'] = 9;

	opMap['+'] = 1;
	opMap['-'] = 1;
	opMap['*'] = 2;
	opMap['/'] = 2;

	//Convert the infix notation into postFix notation
	Queue<char>* postFix = infixToPostFix(&inputQueue);
	//print the postFix Notation
	cout << "Trying to print the returned pointer of postFix" << endl;
	postFix->printList();

	int result = evaluatePostFix(postFix);
	cout << "The result is " << result << endl;

    return 0;
}

Queue<char>* infixToPostFix(Queue<char>* inputQueue){
	Queue<char>* postfix = new Queue<char>();
	Stack<char> opStack;
	//pull from inputQueue one by one and parse then into postfix notation
	char next = inputQueue->pull();
	// char prev = 't';
	while(next){
		cout << "looking at " << next << endl;

		//TODO: If two character in a row were both digit or operator, then the input is invalid
		// if(digitMap.find(prev) == )

		switch(next){
			case '+':
				cout << "It is a +" << endl;
				break;
			case '-':
				cout << "It is a -" << endl;
				break;
			case '*':
				cout << "It is a *" << endl;
				break;
			case '/':
				cout << "It is a /" << endl;
				break;
			case '(':
				cout << "It is a (" << endl;
				break;
			case ')':
				cout << "It is a )" << endl;
				break;
			default:
				cout << "It is not an operation" << endl;
				break;
		}
		//If next char is a digit, push it into the queue
		if (digitMap.find(next) != digitMap.end()){
			cout << "Into the postfixQueue" << endl;
			if(postfix->push(next) == 0){
				cout << "Insertion failed, memory may be full" << endl;
				break;
			}
		}
		else if(next == '(' ){
			cout << "Pushing ( into opStack" << endl;
			if(opStack.push(next) == 0){
				cout << "Insertion failed, memory may be full" << endl;
				break;
			}
		}
		else if(next == ')' ){
			while (opStack.getTop() != '(' ){
				char op = opStack.pop();
				cout << "Pop " << op << " into the postfixQueue" << endl;
				postfix->push(op);
				//If no parantheses is found, error
				if (opStack.isFull() == -1){
					cout << "Error: Mismatched Parantheses" << endl;
					return NULL;
				}
			}
			if (opStack.getTop() == '(' ){
				cout << "Found match opening parantheses, discarded" << endl;
				opStack.pop();
			}
			else {
				cout << "Error: Something Wierd happened while trying to find paratheses." << endl;
				return NULL;
			}
		}
		//If the next char is an operator
		else if(opMap.find(next) != opMap.end()){
			//While the opStack is not empty and the top operation
			//on the stack is of higher precedence of the next
			while(opStack.isFull() != -1 && opMap[opStack.getTop()] > opMap[next]){
				//pop the operation from opStack and push into the postfix queue
				char op = opStack.pop();
				cout << "Pop " << op << " into the postfixQueue" << endl;
				postfix->push(op);
			}

			opStack.push(next);
		}
		else{
			cout << "Invalid Character " << next << " entered" << endl;
		}

		// prev = next;
		next = inputQueue->pull();
		cout << "PostFix Queue: " << endl;
		postfix->printList();
		cout << "opStack Stack: " << endl;
		opStack.printList();
	}
	//unstack all of the remaining operator off of the opStack
	while(opStack.isFull() != -1){
		char op = opStack.pop();
		cout << "Pop " << op << " into the postfixQueue" << endl;
		postfix->push(op);
		postfix->printList();
	}

	return postfix;
}

int evaluatePostFix(Queue<char>* postfixQueue){
	cout << "Start evaluating postFix notation" << endl;
	//Number stack used to store operands
	Stack<int> numberStack;
	char next = postfixQueue->pull();
	while(next){
		cout << "looking at " << next << endl;

		//If next char is a digit, push it into the stack
		if (digitMap.find(next) != digitMap.end()){
			cout << "Pushing " << digitMap[next] << " into the numberStack" << endl;
			if(numberStack.push(digitMap[next]) == 0){
				cout << "Insertion failed, memory may be full" << endl;
				break;
			}
			//
			// cout << "enter a char to continue ";
			// char a;
			// cin >> a;
		}
		//If the next char is an operator
		else if(opMap.find(next) != opMap.end()){
			//pop two numbers and evaluate them using the current operator
			//num2 should be the the first operand because it is in the stack
			//before num1, this way the - and / operation will be correct
			int num1 = numberStack.pop();
			int num2 = numberStack.pop();

			if(!num1 || !num2) {
				cout << "Error: Not enough number on the stack" << endl;
			}
			cout << "Pop " << num1 << " from the numberStack" << endl;
			cout << "Pop " << num2 << " from the numberStack" << endl;

			int result = evaluateHelper(num2, num1, next);
			cout << "Pushing result " << result << " into the stack" << endl;
			numberStack.push(result);

			numberStack.printList();
			// cout << "enter a char to continue ";
			// char a;
			// cin >> a;
		}
		else{
			cout << "Error: invalid character " << next << endl;
		}

		//get the nextNode
		next = postfixQueue->pull();
	}
	return numberStack.pop();
}

int evaluateHelper(int a, int b, char op){
	switch (op){
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
		default:
			cout << "Error: Invalid operator" << endl;
			break;
	}
	return -1;
}
