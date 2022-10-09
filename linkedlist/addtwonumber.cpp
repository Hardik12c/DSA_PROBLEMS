class Solution {
public:
    void insertatend(ListNode *&head, int val)
    {
        if (head == NULL)
        {
            ListNode *n = new ListNode(val);
            head = n;
            return;
        }
        ListNode *n = new ListNode(val);
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    void reversal(ListNode *&head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reversal(l1);
        // reversal(l2);
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;
        int sum = 0;
        while (head1 != NULL && head2 != NULL)
        {
            sum=sum+head1->val+head2->val;
            int enter=sum%10;
            sum=sum/10;
            insertatend(temp,enter);
            head1=head1->next;
            head2=head2->next;
        }
        if(head2==NULL){
            while (head1!=NULL)
            {
                sum+=head1->val;
                int enter=sum%10;
                sum=sum/10;
                insertatend(temp,enter);
                head1=head1->next;
            }
        }
        if(head1==NULL){
            while (head2!=NULL)
            {
                sum=sum+head2->val;
                int enter=sum%10;
                sum=sum/10;
                insertatend(temp,enter);
                head2=head2->next;
            }
        }
        while(sum!=0){
            int enter=sum%10;
            sum=sum/10;
            insertatend(temp,enter);
        }
        ans=ans->next;
        return ans;
    }
};