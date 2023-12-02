class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(-1);
        ListNode* temp= ans;
        ListNode* temp2=head;
        temp2=temp2->next;
        int tempsum=0;
        while(temp2!=NULL){
            tempsum+=temp2->val;

            if(temp2->val==0){
                ListNode* nextNode=new ListNode(tempsum);
                temp->next=nextNode;
                temp=temp->next;
                tempsum=0;
            }
            temp2=temp2->next;
        }
        return ans->next;
    }
};