// There are some basic operations that allow us to perform different actions on a stack.

// Push: Add an element to the top of a stack
// Pop: Remove an element from the top of a stack
// IsEmpty: Check if the stack is empty
// IsFull: Check if the stack is full
// Peek: Get the value of the top element without removing it

#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

template <class X> class Stack{
    int tos,SIZE;
    X *stack;
    public:
    Stack(int);
    void push(X);
    X pop();
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
    void show();
    ~Stack(){
        delete[] stack;
    }
};

template <class X> Stack<X>::Stack(int size){
    stack=new X[size];
    SIZE=size;
    tos=-1;
}

template <class X> void Stack<X>::push(X ele){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    stack[++tos]=ele;
    show();
}

template <class X> X Stack<X>::pop(){
    if (isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return 0;
    }
    tos--;
    show();
    return stack[tos+1];
}

template <class X> X Stack<X>::peek(){
    if (!isEmpty()){
        return stack[tos];
    }
    else{
        cout<<"Stack Underflow"<<endl;
        return 0;
    }
}

template <class X> int Stack<X>::size(){
    return tos+1;
}

template <class X> bool Stack<X>::isEmpty(){
    if (tos==-1) return true;
    else return false;
}

template <class X> bool Stack<X>::isFull(){
    if (tos==SIZE-1) return true;
    else return false;
}

template <class X> void Stack<X>::show(){
    for (int i=tos;i>-1;i--){
        cout<<stack[i]<<endl;
    }
    cout<<endl;
    return;
}

int main(){
    Stack <int> int_stack(5);
    Stack <string> str_stack(5);
    int_stack.push(10);
    int_stack.push(11);
    int_stack.push(12);
    int_stack.push(13);
    int_stack.push(14);
    int_stack.pop();
    int_stack.pop();
    str_stack.push("Jay");
    str_stack.push("Dave");
    cout<<str_stack.size()<<endl;
    return 0;
}