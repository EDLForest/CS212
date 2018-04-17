void Test_console(){

    while (true){
        printf("1- push\n2- pull\n3- front\n4- isFull\n");
        int input;
        scanf(" %d", &input);
        if(input == 1){
            char in;
            printf("Enter char\n");
            scanf(" %c", &in);
            push(q, in);
        }
        else if(input == 2){
            printf("%c\n", pull(q));
        }
        else if(input == 3){
            printf("%c\n", front(q));
        }
        else{
            if(isFull(q))
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
        }
    }
}
