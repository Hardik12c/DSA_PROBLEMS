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
    void recurse(stack<ListNode*> &st,ListNode* head){
        if(head==NULL) return;

        ListNode* temp=head;
        recurse(st,head->next);
        if(st.empty() || temp->val>=st.top()->val) st.push(temp);
    }
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        recurse(st,head);
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(!st.empty()){
            temp->next=st.top();
            temp=temp->next;
            st.pop();
        }
        return ans->next;
    }
};