#ifndef __USERTEST_H__
#define __USERTEST_H__

void Test_console(Queue* q){
    int quit = 0;
    while (!quit){
        printf("1- push\n2- pull\n3- front\n4- isFull\n5- getCurrent\n6- getNext\n7- getPrev\n8- resetToStart\n9- resetToBack\na- Delete\nb- findValue\nc- InsertAfter\nd- deleteCurrent\ne- Quit\n");

        char input;
        char in;
        Node* node;

        scanf(" %c", &input);
        switch (input){
            case '1':
                printf("Enter char\n");
                scanf(" %c", &in);
                push(q, in);
                printf("--------------------\n");
                printf("Pushed %c into the queue.\n", in);
                printf("--------------------\n");
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
                node = getCurrent(q);
                if(node){
                    printf("--------------------------\n");
                    printf("Character of current node is %c\n", node->data);
                    printf("--------------------------\n");
                    break;
                }
                else{
                    printf("---------------------------------\n");
                    printf("The Queue is empty\n");
                    printf("---------------------------------\n");
                    break;
                }
            case '6':
                node = getNext(q, 0);
                if(node){
                    printf("--------------------------\n");
                    printf("Character of previous node is %c\n", node->data);
                    printf("--------------------------\n");
                    break;
                }
                else{
                    printf("---------------------------------\n");
                    printf("The iterator is at the end of the list\n");
                    printf("---------------------------------\n");
                    break;
                }
            case '7':
                node = getNext(q, 1);
                if(node){
                    printf("--------------------------\n");
                    printf("Character of next node is %c\n", node->data);
                    printf("--------------------------\n");
                    break;
                }
                else{
                    printf("---------------------------------\n");
                    printf("The iterator is at the end of the list\n");
                    printf("---------------------------------\n");
                    break;
                }
            case '8':
                printf("---------------------------------\n");
                printf("Setting the iterator to the start\n");
                reset(q, 0);
                node = getCurrent(q);
                if(node)
                    printf("The char at the front is %c\n", node->data);
                else
                    printf("The Queue is empty.\n");
                printf("---------------------------------\n");
                break;
            case '9':
                printf("---------------------------------\n");
                printf("Setting the iterator to the back\n");
                reset(q, 1);
                node = getCurrent(q);
                if(node)
                    printf("The char at the back is %c\n", node->data);
                else
                    printf("The Queue is empty.\n");
                printf("---------------------------------\n");
                break;
            case 'a':
                node = getCurrent(q);
                if(!node) {
                    printf("---------------------------------\n");
                    printf("The Queue is empty\n");
                    printf("---------------------------------\n");
                    break;
                }
                printf("---------------------------------\n");
                printf("Deleting current node containing %c\n", node->data);
                printf("---------------------------------\n");
                Delete(q, node);
                break;
            case 'b':
                printf("Enter char\n");
                scanf(" %c", &in);
                node = findValue(q, in);
                if(node){
                    printf("--------------------\n");
                    printf("node found in the queue at %d.\n", q->posReturned);
                    printf("--------------------\n");
                }
                else{
                    printf("--------------------\n");
                    printf("node not found in the queue.\n");
                    printf("--------------------\n");
                }
                break;
            case 'c':
                printf("Enter char\n");
                scanf(" %c", &in);
                InsertAfter(q, in);
                node = getCurrent(q);

                printf("--------------------\n");
                printf("Inserting %c after %c\n.", in, node->data);
                printf("--------------------\n");
                break;
            case 'd':
                node = getCurrent(q);
                if(node){
                    printf("---------------------------------\n");
                    printf("Deleting current node containing %c\n", node->data);
                    printf("---------------------------------\n");
                    deleteCurrent(q);
                }
                else{
                    printf("---------------------------------\n");
                    printf("Queue is empty.\n");
                    printf("---------------------------------\n");
                }
                break;
            case 'e':
                quit = 1;
                break;
            default:
                printf("invalid input\n");
                break;
        }
    }
}

#endif
