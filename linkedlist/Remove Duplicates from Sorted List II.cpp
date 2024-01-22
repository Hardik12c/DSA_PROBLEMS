class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* ans=new ListNode(-1);
        ListNode* tempans=ans;
        while(temp!=NULL){
            bool flag=true;
            while(temp->next && temp->next->val==temp->val){
                temp->next=temp->next->next;
                flag=false;
            }
            if(flag){
                tempans->next=temp;
                tempans=tempans->next;
            }
            temp=temp->next;

        }
        tempans->next=NULL;
        return ans->next;
    }
};