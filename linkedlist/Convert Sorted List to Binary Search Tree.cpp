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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    void setnull(ListNode* head,ListNode* mid){
        while(head->next!=NULL && head->next!=mid){
            head=head->next;
        }
        head->next=NULL;
    }
    TreeNode* formtree(ListNode* head){
        if(head==NULL) return NULL;
        ListNode* middle=findmiddle(head);
        TreeNode* root=new TreeNode(middle->val);
        ListNode* midnext=middle->next;
        setnull(head,middle);
        if(head==middle) head=NULL;
        root->left=formtree(head);
        root->right=formtree(midnext);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        return  formtree(head);
    }
};