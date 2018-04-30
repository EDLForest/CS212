#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

template <typename T>
class Queue : public List<T> {
    private:
        Node<T>* front;
        Node<T>* back;

    public:
        //Constructor
        Queue();
        //Push the data into the back of the queue
        int push(T data);
        //remove and return the front node of the Queue
        T pull();
        //Return the character of the front node
        T getFront();
        //Return the character of the back node
        T getBack();

};

//Implementation for this header file
#include "queue_impl.h"


#endif
