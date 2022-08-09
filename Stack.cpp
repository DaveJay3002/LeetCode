// There are some basic operations that allow us to perform different actions on a stack.

// Push: Add an element to the top of a stack
// Pop: Remove an element from the top of a stack
// IsEmpty: Check if the stack is empty
// IsFull: Check if the stack is full
// Peek: Get the value of the top element without removing it

#include <stdlib.h>
#include <iostream>

using namespace std;

template<class X> class Stack{
    public:
    int tos,SIZE=10;
    X stack[SIZE];
    Stack(int x){SIZE=x;tos=0;X stack[SIZE];}
    // Stack(){SIZE=10;tos=-1;X stack[SIZE];}
    int isFull(){
        if (tos==SIZE-1) return 1;
        else return 0;
    }
    int isEmpty(){
        if (tos==-1) return 1;
        else return 0;
    }

    void push(X obj){
        if (this->isFull()) cout<<"Stack Overflow"<<endl;
        else{
            stack[tos]=obj;
            this->tos++;
        }
    }

    X pop(){
        if (this->isEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            this->tos--;
            return stack[tos+1];
        }
    }

    X peek(){
        return stack[tos];
    }

    string printStack(){
        string out;
        for (int i=this->tos;i>-1;--i){
            out=out+stack[i]+' ';
        }
        out+='\n';
        return out;
    }

};

int main(){
    Stack <int> S1(15);
    S1.push(17);
    S1.push(18);
    cout<<S1.printStack();
    return 0;
}