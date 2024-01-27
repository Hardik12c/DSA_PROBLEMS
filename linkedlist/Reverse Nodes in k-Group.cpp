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
    ListNode* reverse(ListNode* head,int k,int tot){
        if(head==NULL || tot<k) return head;
        int cnt=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        while(curr!=NULL && cnt<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            cnt++;
        }
        head->next=reverse(curr,k,tot-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int tot=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            tot++;
        }
        return reverse(head,k,tot);
    }
};