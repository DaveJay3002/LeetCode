// Methods	Description
// push()	inserts the element into the priority queue
// pop()	removes the element with the highest priority
// top()	returns the element with the highest priority
// size()	returns the number of elements
// empty()	returns true if the priority_queue is empty

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

template <class X> class Priority{
    int front,rear,SIZE;
    X *queue;
    int *priority;
    public:
    Priority(int);
    void enqueue(X,int);
    X dequeue();
    bool isEmpty();
    bool isFull();
    X peek();
    void show();
};

template <class X> Priority<X>::Priority(int size){
    SIZE=size;
    queue=new X[SIZE];
    priority=new int[SIZE];
    front=rear=-1;
}

template <class X> bool Priority<X>::isFull(){
    return front==0 && rear==SIZE-1;
}

template <class X> bool Priority<X>::isEmpty(){
    return front==-1;
}

template <class X> void Priority<X>::show(){
    if (front==-1) {
        cout<<"Queue empty"<<endl;
        return;
    }
    for (int i=front;i<=rear;i++){
        cout<<queue[i]<<' ';
    }
    cout<<endl;
}


template <class X> void Priority<X>::enqueue(X ele,int p){
    if(isFull() || rear==SIZE-1) {
        cout<<"Queue is full"<<endl;
        return;
    }
    else{
        if (front==-1) front=0;
        rear++;
        queue[rear]=ele;
        priority[rear]=p;
    }
    int i=rear;
    while(i!=0 && priority[i-1]<priority[i]){
        X temp=queue[i];
        int tempi=priority[i];
        queue[i]=queue[i-1];
        queue[i-1]=temp;
        priority[i]=priority[i-1];
        priority[i-1]=tempi;
        i--;
    }
    show();
}

template <class X> X Priority<X>::dequeue(){
    X element;
    if (isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    else{
        element=queue[front];
        if (front>=rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
    show();
    return element;
}

int main(){
    // Priority<int> intq(10);
    // intq.enqueue(15,15);
    // intq.enqueue(12,12);
    // intq.enqueue(17,17);
    // intq.enqueue(18,18);
    // intq.dequeue();
    // intq.dequeue();
    // intq.enqueue(7,7);
    // intq.enqueue(9,9);
    // intq.dequeue();
    // intq.enqueue(15,15);
    // intq.enqueue(12,12);
    // intq.enqueue(17,17);

    Priority<string> strq(5);
    strq.enqueue("Bharat",6);
    strq.enqueue("Jay",8);
    strq.enqueue("Dave",10);
    strq.dequeue();
    strq.dequeue();
    strq.dequeue();

}