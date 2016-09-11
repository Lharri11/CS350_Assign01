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
    //If Stack is full, double capacity of array
    if(top+1 == capacity){
        resize(2 * capacity);
    }
    //"Push" value into stack as array element
    stack[++top] = x;
}
#endif

/* **************************************************************** */

#if POP || ALL
int IntArrayStack::pop(){
    //If Stack is empty, return -1
    if(top == -1){
        return -1;
    }
    else {
        //Assign variable to "topmost" array element
        int pop_val = stack[top];
        //Decrement "topmost" array index
        top--;
        //If stack size is less than 1/3 of array size, halve the size of the array
        if(top+1 <= (capacity/3)){
            resize(capacity/2);
        }
        //"Pop" the topmost value off of the stack
        return pop_val;
    }
}
#endif

/* **************************************************************** */

#if PEEK || ALL
int IntArrayStack::peek(){
    //If Stack is empty, return -1
    if(top == -1){
        return -1;
    }
    else {
        //Assign variable to "topmost" array element
        int peek_val = stack[top];
        //"Peek" at the topmost value of the stack
        return peek_val;
    }
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
bool IntArrayStack::isEmpty(){
    //If "top" = -1, this implies stack is empty
    if(top == -1){
        return true;
    }
        return false;
}
#endif

/* **************************************************************** */

#if EMPTYSTACK || ALL
void IntArrayStack::emptyStack(){
    //Re-initialize stack capacity to 1 and stack array index to -1
    resize(1);
    top = -1;
}
#endif

/* **************************************************************** */

#if RESIZE || ALL
void IntArrayStack::resize(int newCapacity){
    //Update array capacity to new desired capacity
    capacity = newCapacity;

    //Dynamically allocate new array with new desired capacity
    int *newStack = new int[newCapacity];
    //Initialize each new array index with old array elements
    for(int i = 0; i<newCapacity; i++){
        newStack[i] = stack[i];
    }

    //Deallocate old array
    delete[] stack;
    //Assign old array pointer to new array address
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


