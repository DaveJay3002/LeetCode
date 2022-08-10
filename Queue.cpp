// Enqueue: Add an element to the end of the queue
// Dequeue: Remove an element from the front of the queue
// IsEmpty: Check if the queue is empty
// IsFull: Check if the queue is full
// Peek: Get the value of the front of the queue without removing it

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

template <class X> class Queue{
    int front,rear,SIZE;
    X *queue;
    public:
    Queue(int);
    void enqueue(X);
    X dequeue();
    bool isEmpty();
    bool isFull();
    X peek();
    void show();
};

template <class X> Queue<X>::Queue(int size){
    SIZE=size;
    queue=new X[SIZE];
    front=rear=-1;
}

template <class X> bool Queue<X>::isFull(){
    return front==0 && rear==SIZE-1;
}

template <class X> bool Queue<X>::isEmpty(){
    return front==-1;
}

template <class X> void Queue<X>::show(){
    if (front==-1) {
        cout<<"Queue empty"<<endl;
        return;
    }
    for (int i=front;i<=rear;i++){
        cout<<queue[i]<<' ';
    }
    cout<<endl;
}


template <class X> void Queue<X>::enqueue(X ele){
    if(isFull() || rear==SIZE-1) {
        cout<<"Queue is full"<<endl;
        return;
    }
    else{
        if (front==-1) front=0;
        rear++;
        queue[rear]=ele;
    }
    show();
}

template <class X> X Queue<X>::dequeue(){
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
    // Queue<int> intq(3);
    // intq.enqueue(15);
    // intq.enqueue(12);
    // intq.enqueue(17);
    // intq.enqueue(18);
    // intq.dequeue();
    // intq.dequeue();
    // intq.enqueue(7);
    // intq.enqueue(9);
    // intq.dequeue();
    // intq.enqueue(15);
    // intq.enqueue(12);
    // intq.enqueue(17);

    Queue<string> strq(3);
    strq.enqueue("Dave");
    strq.enqueue("Jay");
    strq.enqueue("Bharat");
    strq.enqueue("Bharat");

}