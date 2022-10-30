class Solution {
public:
    ListNode *middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* first ,ListNode* second){
        ListNode* i=first;
        ListNode* j=second;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(i!=NULL && j!=NULL){
            if(i->val<j->val){
                temp->next=i;
                temp=temp->next;
                i=i->next;
            }else{
                temp->next=j;
                temp=temp->next;
                j=j->next;
            }
        }
        if(i==NULL){
            while(j!=NULL){
                temp->next=j;
                temp=temp->next;
                j=j->next;
            }
        }
        if(j==NULL){
            while(i!=NULL){
                temp->next=i;
                temp=temp->next;
                i=i->next;
            }
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head ;
        }
        ListNode *mid = middle(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        left=sortList(left);
        right=sortList(right);

        head= merge(left, right);
        return head;
    }
};