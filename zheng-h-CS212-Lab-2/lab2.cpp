#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char* readFile(char* fileName);

int main (int argc, char* argv[])
{

	char* input = (char*)malloc(101);
	int8_t i;
	if (argc == 2)
	{
		printf("Reading from user specified file name: %s\n", argv[1]);
		
		input = readFile(argv[1]);
		if(input == NULL)
		{
			printf("Invalid File name.\n");
			return -1;
		}
	}
	else
	{
		printf("Please enter text from keyboard\n");
		char in;		
		for(i = 0; i < 100; i++)
		{
			scanf("%c", &in);
			if (in == '\n' || in == '\0' || in == EOF)
			{
				printf("Line ended. \n");
				break;
			}
			input[i] = in;
		}
	
		//Insert a null terminator at the end of the input
		input[i] = '\0';
	}
	
	//Read from a file
	//printf("\nprinting the text file\n");
	//char* textInput = readFile("./test.txt");
	//int8_t i;
	//for(i = 0; i < strlen(textInput); i++)
	//{
	//	printf("%c", textInput[i]);
	//}
	
	
	/***********************************************/
	/**********Printing the Char array**************/
	printf("\nyou have inputted:\n");
	for(i = 0; i < strlen(input); i++)
	{
		printf("%c", input[i]);
	}
	printf("\n");
	
	printf("\nNow printing the inputted message backward\n");
	for(i = strlen(input)-1; i >= 0; i--)
	{
		printf("%c", input[i]);
	}
	printf("\n");
	
	printf("\nNow printing the Odd char\n");
	for(i = 1; i < strlen(input); i+=2)
	{
		printf("%c", input[i]);
	}
	printf("\n");
	
	printf("\nNow printing the Even char\n");
	for(i = 0; i < strlen(input); i+=2)
	{
		printf("%c", input[i]);
	}
	printf("\n");
	/***********************************************/
	
	
	
	return 0;
}


char* readFile(char *fileName)
	{
		//open a file in reading mode
		FILE *file;
		file = fopen(fileName, "r");
		
		//If the file specified is null, return null
		if(file == NULL)
			return NULL;
		
		char* code = (char*)malloc(101);	//allocate 101 bytes of memory for the code;
		size_t n = 0;
		int c;
		//while we are not at the End Of File
		//and we are not exceeding the 100 char limit
		//get a character from file 
		while ( (c = fgetc(file)) != EOF && n < 100)
		{
			//insert the char to the end of the code array 
			code[n] = (char)c;
			n++;
		}
		//Insert the null terminator at the end
		code[n] = '\0';
		
		return code;
	}
