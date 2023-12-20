/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next;
        if(head->val>=x){
            next=head;
        }else{
            while(temp->next!=NULL && temp->next->val<x){
                temp=temp->next;
            }
            if(temp->next==NULL) return head;
            prev=temp;
            temp=temp->next;
            next=temp;
        }
        temp=next;
        while(temp->next!=NULL){
            if(temp->next->val<x){
                ListNode* mid=temp->next;
                temp->next=temp->next->next;
                if(!prev){
                    mid->next=next;
                    prev=mid;
                    head=mid;
                }else{
                    prev->next=mid;
                    mid->next=next;
                    prev=mid;
                }
            }else temp=temp->next;
        }
        return head;
    }
};