#ifndef USERTEST_H
#define USERTEST_H

void Test_console(Queue* q){
    int quit = 0;
    while (!quit){
        printf("1- push\n2- pull\n3- ront\n4- isFull\n5- Quit\n");
        char input;
        char in;
        scanf(" %c", &input);
        switch (input){
            case '1':
                printf("Enter char\n");
                scanf(" %c", &in);
                push(q, in);
                printf("--------------------");
                printf("Pushed %c into the queue.", in);
                printf("--------------------");
                break;
            case '2':
                printf("-------------\n");
                printf("%c is pulled from queue\n", pull(q));
                printf("-------------\n");
                break;
            case '3':
                printf("-------------\n");
                printf("%c is at the front of queue\n", front(q));
                printf("-------------\n");
                break;
            case '4':
                if(isFull(q) == -1)
                    printf("queue is empty\n");
                else if(isFull(q) == 1)
                    printf("queue is full\n");
                else
                    printf("queue is neither full nor empty.\n");
                break;
            case '5':
                quit = 1;
                break;
            default:
                printf("invalid input\n");
        }
    }
}

#endif
