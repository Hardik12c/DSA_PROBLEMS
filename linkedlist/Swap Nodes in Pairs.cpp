class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        ListNode* ans=head->next;
        ListNode* helper=new ListNode(-1);
        while(temp!=NULL && temp->next!=NULL){
            ListNode * next=temp->next;
            ListNode* prev=next->next;
            temp->next=prev;
            next->next=temp;
            helper->next=next;
            helper=temp;
            temp=temp->next;
        }
        return ans;
    }
};