#include <cstdlib>
#include <iostream>
#include "queue.h"
#include "List.h"

template <typename T>
Queue<T>::Queue(){
    front = List<T>::getCurrent();
    back = List<T>::getCurrent();
}

template <typename T>
int Queue<T>::push (T data){
    List<T>::resetIterator(1);
    return List<T>::insertAfter(data);
}

template <typename T>
T Queue<T>::pull(){
    List<T>::resetIterator(0);
    Node<T>* nodePtr = List<T>::getCurrent();
    //If getCurrent returns NULL, return '\0'
    if(nodePtr == NULL) return '\0';
    //else, return the data of the node
    T data = nodePtr->data;
    List<T>::deleteCurrent();
    return data;
}

template <typename T>
T Queue<T>::getFront(){
    List<T>::resetIterator(0);
    Node<T>* node = List<T>::getCurrent();
    if(node == NULL) return '\0';
    return node->data;
}

template <typename T>
T Queue<T>::getBack(){
    List<T>::resetIterator(1);
    Node<T>* node = List<T>::getCurrent();
    if(node == NULL) return '\0';
    return node->data;
}
