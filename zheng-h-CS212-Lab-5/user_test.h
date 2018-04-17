#ifndef USER_TEST_H
#define USER_TEST_H

    void Test_console(Stack* s){
        int quit = 0;
        while (!quit){
            printf("1- push\n2- pop\n3- top\n4- isFull\n5- Quit\n");
            char input;
            char in;
            scanf(" %c", &input);
            switch (input){
                case '1':
                    printf("Enter char\n");
                    scanf(" %c", &in);
                    push(s, in);
                    break;
                case '2':
                    printf("-------------\n");
                    printf("%c is popped from stack\n", pop(s));
                    printf("-------------\n");
                    break;
                case '3':
                    printf("-------------\n");
                    printf("%c is on top of stack\n", top(s));
                    printf("-------------\n");
                    break;
                case '4':
                    if(isFull(s))
                        printf("stack is full\n");
                    else
                        printf("stack is not full\n");
                    break;
                case '5':
                    quit = 1;
                    break;
                default:
                    printf("invalid input\n");
            }
            // if(input == 1){
            //     char in;
            //     printf("Enter char\n");
            //     scanf(" %c", &in);
            //     push(q, in);
            // }
            // else if(input == 2){
            //     printf("%c\n", pull(q));
            // }
            // else if(input == 3){
            //     printf("%c\n", front(q));
            // }
            // else{
            //     if(isFull(q))
            //         printf("Queue is full\n");
            //     else
            //         printf("Queue is not full\n");
            // }
        }
    }

#endif
