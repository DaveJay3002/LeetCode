#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

template <class X> class HashTable{
    int capacity;
    list<X> *table;
    public:
    HashTable(int V);
    void insertitem(int key,X ele);
    void deleteitem(int key);
    void displayhash();

    int checkprime(int n){
        int i;
        if (n==1 || n==0) return 0;
        for (i=2;i<n/2;i++){
            if (n%i==0) return 0;
        }
        return 1;
    }

    int getprime(int n){
        if (n%2==0) n++;
        while(!checkprime(n)) n+=2;
        return n;
    }

    int hashfunc(int key){
        return (key%capacity);
    }
} ;

template<class X> HashTable<X>::HashTable(int V){
    this->capacity=getprime(V);
    table=new list<X>[capacity];
}

template<class X> void  HashTable<X>::insertitem(int key,X ele){
    int index=hashfunc(key);
    table[index].push_back(ele);
}

template<class X> void HashTable<X>::deleteitem(int key){
    int index=hashfunc(key);
    typename list<X>::iterator i;
    for(i=table[index].begin();i!=table[index].end();i++){
        cout<<*i<<' ';
    }    
    cout<<endl;
}

template<class X> void HashTable<X>::displayhash(){
    for(int i=0;i<capacity;i++){
        cout<<"table["<<i<<']';
        for (auto x:table[i]){
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
}

int main(){
    auto start=chrono::high_resolution_clock::now();

    int keys[]={231, 321, 212, 321, 433, 262, 56,65,45,789,13,456,123,159,15,48,36,78,89,20,56,8465,1354,789,135};
    string data[]={"Lorem", "Ipsum", "is", "simply", "dummy", "text", "of", "the", "printing", "and", "typesetting", "industry.", "Lorem", "Ipsum", "has", "been", "the", "industry's", "standard", "dummy", "text", "ever", "since", "the", "1500s"};
    int size=sizeof(keys)/sizeof(keys[0]);
    
    HashTable<string> ht(size);

    for(int i=0;i<size;i++){
        ht.insertitem(keys[i],data[i]);
    }

    ht.displayhash();

    ht.deleteitem(321);

    // ht.displayhash();

    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(end-start);
    cout<<"Program finished executing in "<<duration.count()<<"ms"<<endl;
    return 0;
}