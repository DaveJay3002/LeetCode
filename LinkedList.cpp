// Traversal - access each element of the linked list
// Insertion - adds a new element to the linked list
// Deletion - removes the existing elements
// Search - find a node in the linked list
// Sort - sort the nodes of the linked list

#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

template <class X> struct node{
    X data;
    int index;
    node* next;
};

template<class X> class LinkedList{
    node<X> *head,*tail,*cur;
    int count;
    public:
    LinkedList();
    void insert(X);
    void remove(X);
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

template<class X> void LinkedList<X>::remove(X ele){
    cur=head;
        if (head->data==ele){
            delete head;
            head=head->next;
            count--;
            break;
        }
    while(cur!=tail){
        else if(cur->next->data==ele){
            node<X> *temp;
            temp=cur->next;
            cur->next=cur->next->next;
            delete temp;
            count--;
            break;
        }
        else{
            cur=cur->next;
        }
    }
    if (cur==tail && tail->data=ele){
        cout<<"Node not found"<<endl;
    }
}

template<class X> void LinkedList<X>::show(){
    cur = head;
    if(count==0){
        cout<<"List empty"<<endl;
    }
    else if(count ==1){
        cout<<cur->data<<endl;
    }
    else{
    do{
        cout<<cur->data<<"->";
        cur=cur->next;
    }while (cur!=tail);
    cout<<tail->data<<endl;
    }
}

int main(){
    auto start=chrono::high_resolution_clock::now();
    LinkedList<string> mylist;
    mylist.insert("Hi");
    mylist.insert("Hi2");
    mylist.insert("Hi3");
    mylist.insert("Hi4");
    mylist.insert("Hi5");
    mylist.insert("Hi7");
    mylist.insert("Hi8");
    mylist.insert("Hi9");
    mylist.insert("Hi11");
    mylist.show();
    mylist.remove("Hi");
    mylist.remove("Hi2");
    mylist.remove("Hi3");
    mylist.remove("Hi4");
    mylist.remove("Hi5");
    mylist.remove("Hi7");
    mylist.remove("Hi8");
    mylist.remove("Hi9");
    mylist.remove("Hi11");
    mylist.show();
    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(end-start);
    cout<<"Program finished executing in "<<duration.count()<<"ms"<<endl;
}