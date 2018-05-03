#include <cstdlib>
#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
Node<T>* List<T>::getCurrent(){
    return iterator;
}
template <typename T>
Node<T>* List<T>::getNext(int direction){
    if(isFull() == -1) {
        cout << "The List is empty"<< endl;
        return NULL;
    }

    if (direction == 1){
		if(iterator == back){
			return NULL;
		}
        else{
			iterator = iterator->next;
			return getCurrent();
        }
	}
    else if(direction == 0){
		if(iterator == front){
			return NULL;
		}
		else{
			iterator = iterator->prev;
			return getCurrent();
		}
	}
	else{	//invalid direction
		return NULL;
	}

}

template <typename T>
Node<T>* List<T>::findValue(T value){
    if(isFull() == -1) {
        cout << "The List is empty"<< endl;
        return NULL;
    }
    else{
        Node<T>* current = front;
		// q->posReturned = 0;
		while(current != Anchor){
			if (current->data == value) return current;
			current = current->next;
			// q->posReturned++;
		}
		// q->posReturned = -1;
		return NULL;
    }
}

template <typename T>
void List<T>::resetIterator(int direction){
    if (direction == 0)
		iterator = front;
	else if(direction == 1)
		iterator = back;
    else{
        return;
    }
}

template <typename T>
int List<T>::isFull(){
    //If the front and/or back is equals to the Anchor of the Queue
	//The queue is empty
	if(front == Anchor)	{
        return -1;
    }
    //If malloc return Null, then the queue is full
	Node<T>* p;
	if( ( p = (Node<T>*)malloc(sizeof(Node<T>)) ) == NULL ){
		free(p);
		return 1;
	}
    else{
		free(p);
		return 0;
	}
}

template <typename T>
int List<T>::insertAfter(T value){
    if(isFull() == 1) return 0;
    //Create a new Node pointer
    Node<T>* node = new Node<T>(value);

    if (iterator == Anchor){
        front = node;
        back = node;
        iterator = node;
        Anchor->prev = node;
        node->next = Anchor;
    }
    //if iterator at the back of the list
    //change both iterator, back and anchor will be changed.
    else if (iterator == back){
        back = node;
        iterator->next = node;
        node->prev = iterator;
        node-> next = Anchor;
        Anchor-> prev = node;
    }
    //If the iterator is at any other places
    else{
        node->next = iterator->next;
        node->prev = iterator;
        iterator->next->prev = node;
        iterator->next = node;
    }
    return 1;
}

template <typename T>
int List<T>::insertBefore(T value){
    if(isFull() == 1) return 0;
    //Create a new Node pointer
    Node<T>* node = new Node<T>(value);
    //If the list is empty
    if (iterator == Anchor){
        front = node;
        back = node;
        iterator = node;
        Anchor->prev = node;
        node->next = Anchor;
    }
    //if iterator at the back of the list
    //change both iterator, back and anchor will be changed.
    else if (iterator == front){
        front = node;
        iterator->prev = node;
        node->next = iterator;
    }
    //If the iterator is at any other places
    else{
        node->prev = iterator->prev;
        node->next = iterator;
        iterator->prev->next = node;
        iterator->prev = node;
    }
    return 1;
}

template <typename T>
void List<T>::deleteCurrent(){
    //if the queue is empty, then there is nothing to delete
	if (isFull() == -1) return;
    //if there is only one node in the queue
	//back, front and iterator will points to the same node
	//Delete that node and reset the front, back, and iterator to the anchor
	else if (front == back){
		free(iterator);
		front = Anchor;
		back = Anchor;
		iterator = Anchor;
	}
    else{
		if(iterator == front){
			Node<T> temp = *(iterator);
			free(iterator);
			front = temp.next;
			iterator = front;
		}
		else if(iterator == back){
			Node<T> temp = *(iterator);
			free(iterator);
			back = temp.prev;
			back->next = Anchor;
			Anchor->prev = back;
			iterator = back;
		}
		else{
			Node<T> temp = *(iterator);
			free(iterator);
			//previousNode's nextNode points to the nextNode of currentNode
			temp.prev->next = temp.next;
            //nextNode's previousNode points to the previousNode of currentNode
            temp.next->prev = temp.prev;
			iterator = temp.next;
		}
    }
}

template <typename T>
int List<T>::Delete(Node<T>* target){
    //If the queue is empty, then there is nothing to Delete
	//return 0
	if(isFull() == -1) return 0;

    //Remember the current position of the iterator
    Node<T>* original = iterator;
    Node<T>* current = front;
    resetIterator(0);
    do{
        if (current == target) {
            iterator = current;
            deleteCurrent();
            iterator = original;
            return 1;
        }
        else{
            current = current->next;
        }
    }while(current != Anchor);

    return 0;
}

template <typename T>
void List<T>::printList(){
	T output;
	//reset the iterator to print the contents
	resetIterator(0);
	do {//While the output pointer points a non Null value
		output = getCurrent()->data;
		cout <<  " " << output;
		if(!getNext(1)) break;
	} while(output != '\0');

	cout << endl;
	//reset iterator after printing
	resetIterator(0);
}
