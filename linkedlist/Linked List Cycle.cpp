class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL && fast !=NULL){
            fast=fast->next;
            if(!fast) return false;
            else fast=fast->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};