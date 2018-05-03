#ifndef STACK_H
#define STACK_H
#include "List.h"

    template <typename T>
    class Stack: public List<T> {
        // using namespace Stack;
        private:
            Node<T>* top;

        public:
            //Constructtor
            Stack();
            //push the data onto the stack
            int push(T data);
            //Remove and return the node on top of the stack
            T pop();
            //See the char top of the stack
            T getTop();

    };

//Implementation for this header file
#include "stack_impl.h"


#endif
