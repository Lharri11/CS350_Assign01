//
//  IntArrayStack.cpp
//

#include "IntArrayStack.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
IntArrayStack::IntArrayStack(){
    //Initialize variables
    capacity = 1;
    top = -1;

    //Dynamically allocate initial array
    stack = new int[1];
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
IntArrayStack::~IntArrayStack() {
    //Deallocate initial array
    delete[] stack;
}
#endif

/* **************************************************************** */

#if PUSH || ALL
void IntArrayStack::push(int x){
    if(top+1 == capacity){
        resize(2 * capacity);
    }
    stack[++top] = x;
}
#endif

/* **************************************************************** */

#if POP || ALL
int IntArrayStack::pop(){
    if(top == -1){
        return -1;
    }
    else {
        int pop_val = stack[top];
        top--;
        if(top+1 <= (capacity/3)){
            resize(capacity/2);
        }
        return pop_val;
    }
}
#endif

/* **************************************************************** */

#if PEEK || ALL
int IntArrayStack::peek(){
    if(top == -1){
        return -1;
    }
    else {
        int peek_val = stack[top];
        return peek_val;
    }
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
bool IntArrayStack::isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}
#endif

/* **************************************************************** */

#if EMPTYSTACK || ALL
void IntArrayStack::emptyStack(){
    resize(1);
    top = -1;
}
#endif

/* **************************************************************** */

#if RESIZE || ALL
void IntArrayStack::resize(int newCapacity){
    capacity = newCapacity;

    int *newStack = new int[newCapacity];
    for(int i = 0; i<newCapacity; i++){
        newStack[i] = stack[i];
    }

    delete[] stack;
    stack = newStack;
}
#endif

/* **************************************************************** */
// Do NOT modify anything below this line
/* **************************************************************** */

#ifndef BUILD_LIB
void IntArrayStack::printStack()
{
    std::cout << std::endl;
    std::cout << "Current array size: " << capacity << std::endl;
    std::cout << "Number of ints in stack: " << top+1 << std::endl;
    for (int i=top; i >= 0; i--)
    {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}


int IntArrayStack::getCapacity()
{
  return capacity;
}


int IntArrayStack::getSize()
{
  return top+1;
}


int IntArrayStack::getTop()
{
  return top;
}


void IntArrayStack::toArray(int* arr)
{
  for (int i=top; i >= 0; i--)
  {
    arr[i] = stack[i];
  }
}
#endif

/* **************************************************************** */


