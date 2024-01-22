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
    ListNode* oddEvenList(ListNode* head) {
        bool flag=true;
        if(!head || !head->next) return head;
        ListNode* odd=head;
        ListNode* evenhead=head->next;
        ListNode* eventemp=head->next;
        ListNode* temp=head->next->next;
        while(temp!=NULL){
            if(flag){
                odd->next=temp;
                odd=odd->next;
                flag=false;
            }else{
                eventemp->next=temp;
                eventemp=eventemp->next;
                flag=true;
            }
            temp=temp->next;
        }
        odd->next=evenhead;
        eventemp->next=NULL;
        return head;
    }
};