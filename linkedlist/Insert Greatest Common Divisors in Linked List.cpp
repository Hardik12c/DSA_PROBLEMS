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
private:
    int GCD(int a, int b){
        int div=min(a,b);
        while(div>0){
            if(a%div==0 && b%div==0){
                break;
            }
            div--;
        }
        return div;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode* head1=head;
        ListNode* head2=head->next;
        while(head2!=NULL){
            int gcd=GCD(head1->val,head2->val);
            cout<<gcd<<endl;
            ListNode* temp=new ListNode(gcd);
            temp->next=head2;
            head1->next=temp;
            head1=head2;
            head2=head2->next;
        }
        return head;
    }
};