#include <cstdlib>
#include <iostream>
#include "stack.h"
#include "List.h"

template <typename T>
Stack<T>::Stack(){
    top = List<T>::getCurrent();
}

template <typename T>
int Stack<T>::push(T data){
    List<T>::resetIterator(0);
    return List<T>::insertBefore(data);
}

template <typename T>
T Stack<T>::pop(){
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
T Stack<T>::getTop(){
    List<T>::resetIterator(0);
    Node<T>* node = List<T>::getCurrent();
    if(node == NULL) return '\0';
    return node->data;
}
