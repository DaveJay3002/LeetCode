#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int fir,sec;
        ListNode* x=l1;
        for (int i=0;x!=nullptr;i++){
            
        }

    }
}; 

int main(){
    ListNode* head1,*head2,*temp;
    head1= new ListNode(2);
    temp=new ListNode(4);
    head1->next=temp;
    temp= new ListNode(3);
    head1->next->next=temp;
    for (temp=head1;temp!=nullptr;temp=temp->next){
        cout<<temp->val<<endl;
        cout<<temp->next<<endl;
    }

    
}