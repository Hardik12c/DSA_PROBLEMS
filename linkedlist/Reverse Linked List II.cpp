
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head,int count,int right){
        ListNode* start =NULL;
        ListNode* mid=head;
        ListNode* end=head->next;
        while(mid!=NULL && count<right){
            mid->next=start;
            start=mid;
            mid=end;
            end=end!=NULL?end->next:NULL;
            count++;
        }
        head->next=mid;
        return start;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int count=1;
        ListNode* temp=head;
        while(count<left-1){
            temp=temp->next;
            count++;
        }
        ListNode* reverseHead=reverseLinkedList(left!=1?temp->next:temp,left!=1?count:0,right);
        if(left==1) return reverseHead;
        temp->next=reverseHead;
        return head;
    }
};