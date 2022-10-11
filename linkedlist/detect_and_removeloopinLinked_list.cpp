#include <iostream>
// #include "bits/stdc++.h"
#include <math.h>
#include <string>
#include <array>

using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertatend(node* &head,int val){
    node* temp=head;
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void addloop(node* &head){
    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=(head->next)->next;
}
// if we only check for loop then we will make bool function here to check but we are now finding their intersection as fast and slow pointer intersect so we are making it node* and passing it to other function
node* checkloop(node* &head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=(fast->next);
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;    
} 
// we are getting intersection pointer from here and then after finding intersection we will set a pointer at start and one pointer at intersection and then we will start iterating when the pointer meet that is the starting of loop
node* startnode(node* &head){
    node* intersection=checkloop(head);
    if(intersection==NULL){
        return NULL;
    }
    node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
// finding the starting of the loop then traversing the node till we will reach that node again to remove the cycle
void removecycle(node* &head){
    node* initial=startnode(head);
    if(initial==NULL){
        return ;
    }
    node* temp=initial;
    while(temp->next!=initial){
        temp=temp->next;
    }
    temp->next=NULL;
}
int main(){
    node* head=NULL;
    insertatend(head,10);
    insertatend(head,20);
    insertatend(head,30);
    insertatend(head,40);
    insertatend(head,50);
    insertatend(head,60);
    // addloop(head);
    removecycle(head);
    if(checkloop(head)==NULL){
        cout<<"no";
    }else{
        cout<<"yes";
    }
    return 0;
}