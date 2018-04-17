#include "tstdata.h"
#include "arrayQueue.h"

int main(){

    //initialize
    Queue* q;
    queueInit(q);

    printf("Queue size = %d\n", QUEUESZ);
    printf("Please enter chars to be pushed into the queue.\n");

    char input;
    while(true){
        scanf(" %c", &input);
        if(input == '^') break;

        if ( isFull(q) ){
            printf("The queue is full, enter '^' character to stop input.\n");
        }
        else{
            push(q, input);
        }
    }

    printf("Input ended, now printing the entire queue\n");
    char output = '0';
    while( output != '\0'){
        output = pull(q);
        printf("%c\n", output);
    }


    return 0;
}
