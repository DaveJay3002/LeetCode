#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <vector>

using namespace std;

template<class X> void swap(X* a,X* b){
    X temp=*b;
    *b=*a;
    *a=temp;
}



int main(){
    auto start=chrono::high_resolution_clock::now();

    

    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(end-start);
    cout<<"Program finished executed in "<<duration.count()<<"ms"<<endl;
    return 0;
}