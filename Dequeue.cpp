#include <iostream>
#include <string>
#include <stdlib.h>
 
using namespace std;

template <class X> class DeQueue{
    int front,rear,SIZE;
    X *queue;
    public:
    DeQueue(int);
    void pushfront(X);
    void pushback(X);
    X popfront();
    X popback();
    bool isEmpty();
    bool isFull();
    void show();
};

template <class X> DeQueue<X>::DeQueue(int x){
    SIZE=x;
    queue= new X[SIZE];
    front=rear=-1;
}

template <class X> bool DeQueue<X>::isEmpty(){
    return front==-1;
}

template <class X> bool DeQueue<X>::isFull(){
    return (front==0 && rear==SIZE-1) || (front==rear+1);
}

template <class X> void DeQueue<X>::show(){
    if (isEmpty()) {
        cout<<"Queue empty"<<endl;
        return;
    }
    for (int i=0;i<SIZE;i++){
        cout<<queue[i]<<' ';
    }
    cout<<endl;
}

template <class X> void DeQueue<X>::pushfront(X ele){
    if (isFull()){
        cout<<"Queue is Full"<<endl;
        return;
    }
    else{
        if (front<1) {
            front=SIZE-1;
        }
        else {
            front=front-1;
        }
        queue[front]=ele;
    }
    show();
}

template <class X> void DeQueue<X>::pushback(X ele){
    if (isFull()){
        cout<<"Queue is Full"<<endl;
        return;
    }
    else{
        if (front==-1) front=0;
        rear++;
        queue[rear]=ele;
    }
    show();
}

template <class X> X DeQueue<X>::popfront(){
    if (isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    X temp;
    if (front==rear){
        temp=queue[front];
        queue[front]=false;
        front=rear=-1;
    }
    else if (front==SIZE-1){
        temp=queue[front];
        queue[front]=false;
        front=0;
    }
    else{
        temp=queue[front];
        queue[front]=false;
        front++;
    }
    show();
    return temp;
}

template <class X> X DeQueue<X>::popback(){
    if (isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    X temp;
    if (front==rear){
        temp=queue[rear];
        queue[rear]=false;
        front=rear=-1;
    }
    else if (rear==0){
        temp=queue[rear];
        queue[rear]=false;
        rear=SIZE-1;
    }
    else{
        temp=queue[rear];
        queue[rear]=false;
        rear--;
    }
    show();
    return temp;
}

int main(){
    DeQueue<string> dqstr(5);
    dqstr.pushback("Jay");
    dqstr.pushback("Jay");
    dqstr.pushfront("Jay");
    dqstr.pushfront("Jay");
    dqstr.pushfront("Jay");
    dqstr.pushfront("Jay");
    dqstr.popfront();
    dqstr.popback();
    dqstr.popfront();
    dqstr.popback();
    dqstr.popfront();
    
    return 0;
}