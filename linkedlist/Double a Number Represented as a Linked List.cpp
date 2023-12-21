class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* mid=head;
        ListNode* next;
        while(mid!=NULL){
            next=mid->next;
            mid->next=prev;
            prev=mid;
            mid=next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=reverse(head);
        ListNode* newTemp=temp;
        int carry=0;
        ListNode* tail;
        while(newTemp!=NULL){
            if(newTemp->next==NULL) tail=newTemp;
            int value=(newTemp->val*2)+carry;
            newTemp->val=value%10;
            carry=(value)/10;
            newTemp=newTemp->next;
        }
        while(carry!=0){
            ListNode* newNode= new ListNode(carry%10);
            carry/=10;
            tail->next=newNode;
        }
        return reverse(temp);
    }
};