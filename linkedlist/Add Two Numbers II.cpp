class Solution {
public:
    ListNode* reverseNode(ListNode* head){
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1reverse=reverseNode(l1);
        ListNode* l2reverse=reverseNode(l2);
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(l1reverse!=NULL && l2reverse!=NULL){
            int num=l1reverse->val+l2reverse->val+carry;
            ListNode* newNode=new ListNode(num%10);
            carry=num/10;
            temp->next=newNode;
            temp=temp->next;
            l1reverse=l1reverse->next;
            l2reverse=l2reverse->next;
        }
        while(l1reverse!=NULL){
            int num=l1reverse->val+carry;
            ListNode* newNode=new ListNode(num%10);
            carry=num/10;
            temp->next=newNode;
            temp=temp->next;
            l1reverse=l1reverse->next;
        }
        while(l2reverse!=NULL){
            int num=l2reverse->val+carry;
            ListNode* newNode=new ListNode(num%10);
            carry=num/10;
            temp->next=newNode;
            temp=temp->next;
            l2reverse=l2reverse->next;
        }
        while(carry!=0){
            ListNode* newNode=new ListNode(carry%10);
            carry/=10;
            temp->next=newNode;
            temp=temp->next;
        }
        return reverseNode(ans->next);
    }
};