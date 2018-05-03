#ifndef LIST_H
#define LIST_H

template <typename T>
class Node{
    public:
        Node(T data){
            this->data = data;
        }
        T data;
        Node<T>* next;
        Node<T>* prev;
};


template <typename T>
class List {
    // using namespace List;
    protected:
        Node<T>* front;
        Node<T>* back;
        Node<T>* Anchor;
        Node<T>* iterator;

    public:
        //Constructor for the List
        List(){
            this->Anchor = (Node<T>*) malloc(sizeof(Node<T>));
            this->back = Anchor;
            this->front = Anchor;
            this->iterator = Anchor;
        }
        //return the next or prev of the current iterator
        Node<T>* getNext(int direction);
        //return the current iterator
        Node<T>* getCurrent();
        //Detete the current node
        void deleteCurrent();
        //Insert a new node after the iterator(next). return 0 for fail and 1 for success
        int insertAfter(T value);
        //Insert a new node before the iterator(prev). return 0 for fail and 1 for success
        int insertBefore(T value);
        //find and return the node with corresponding data
        Node<T>* findValue(T value);
        //reset the position of the iterator to either the front or back
        void resetIterator(int direction);
        //Delete the target node in this list, return 1 for success, 0 for fail
        int Delete(Node<T>* target);
        //checkto see if the list is Full
        int isFull();
        //Print the List from front to back
        void printList();
};

//Implementation for this header file
#include "List_impl.h"



#endif
