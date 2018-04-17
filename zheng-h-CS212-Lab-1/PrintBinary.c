#include <stdint.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

	if(argc > 2){
		printf("You have entered more than one arguments, only the first one will be used.\n");	
	}
	
	//Obtain the first argument passed to the main function
	int8_t input = atoi(argv[1]);
	printf("you entered %d\n", input);
	if(input < 0 || input > 32){
		printf("The numbere entered is invalid!\n");
		return -1;
	}
	
	//Since we are only converting numbers from 0 to 32, 6 bits(5 downto 0) is enough
	int8_t bitCount;
	int8_t LSB;
	for(bitCount = 5; bitCount >= 0; bitCount--){
		//Logical right shift the bitCount-th bit of input down to the least significant position
		LSB = input >> bitCount;
		
		//bit mask the least significant bit with an 1, it returns whatever
		//the least significant bit is.
		if(LSB & 1){	
			printf("1");
		}
		else{
			printf("0");
		}
	}
	
	printf("\n");
	
	return 0;

}
