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


//another solution with less time complexity
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            cout<<" hi"<<endl;
            int sum=l1->val+l2->val+carry;
            temp->next=new ListNode((sum)%10);
            carry=sum/10;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=NULL){
            int sum=l1->val+carry;
            temp->next=new ListNode((sum)%10);
            carry=sum/10;
            temp=temp->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            int sum=l2->val+carry;
            temp->next=new ListNode((sum)%10);
            carry=sum/10;
            temp=temp->next;
            l2=l2->next;
        }
        while(carry!=0){
            temp->next=new ListNode((carry)%10);
            carry/=10;
            temp=temp->next;
        }
        return head->next;
    }
};