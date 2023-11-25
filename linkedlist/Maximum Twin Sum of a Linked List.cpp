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
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode* slow=head;
        ListNode* fast=head->next;
        s.push(slow->val);
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            s.push(slow->val);
        }
        int ans=INT_MIN;
            slow=slow->next;
        while(slow!=NULL){
            ans=max(ans,(slow->val+s.top()));
            slow=slow->next;
            s.pop();
        }
        return ans;
    }
};