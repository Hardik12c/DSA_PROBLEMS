class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next||k==0) return head;
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        k%=size;
        if(k==0) return head;
        int count=0;
        temp=head;
        ListNode* temp2;
        ListNode* ans;
        while(temp->next!=NULL){
            count++;
            if(count==size-k){
                temp2=temp;
                ans=temp->next;
            }
            temp=temp->next;
        }
        temp2->next=NULL;
        temp->next=head;
        return ans;
    }
};