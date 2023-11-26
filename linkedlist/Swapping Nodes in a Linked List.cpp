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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int second=count-k+1;
        temp=head;
        count=0;
        if(second<k) swap(k,second);
        ListNode* first;
        while(temp!=NULL){
            count++;
            if(count==k){
                first=temp;
            }
            if(count==second){
                swap(first->val,temp->val);
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};