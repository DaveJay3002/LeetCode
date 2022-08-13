// Traversal - access each element of the linked list
// Insertion - adds a new element to the linked list
// Deletion - removes the existing elements
// Search - find a node in the linked list
// Sort - sort the nodes of the linked list

#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <class X> struct node{
    X data;
    int index;
    node* next;
    node(){};
};

template<class X> class LinkedList{
    node<X> *head,*tail,*cur;
    int count;
    public:
    LinkedList();
    void insert(X);
    void show();
};

template<class X> LinkedList<X>::LinkedList(){
    count=0;
}

template<class X> void LinkedList<X>::insert(X ele){
    if (count==0){
        head= new node<X>;
        head->data=ele;
        head->index=count;
        cur=head;
        tail=head;
        count++;
    } 
    else{
        node<X> *temp;
        temp=new node<X>;
        cur->next=temp;
        cur =temp;
        cur->data=ele;
        cur->index=count;
        tail=cur;
        count++;
    }
}

template<class X> void LinkedList<X>::show(){
    cur = head;
    do{
        cout<<cur->data<<"->";
        cur=cur->next;
    }while (cur!=tail);
    cout<<tail->data;
    cout<<endl;
}

int main(){
    LinkedList<string> mylist;
    mylist.insert("Hi");
    mylist.insert("Hello");
    mylist.insert("Hello");
    mylist.show();
}