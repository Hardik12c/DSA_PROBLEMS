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
    bool isfind(ListNode* temp,TreeNode* root){
        if(temp==NULL) return true;
        if(root==NULL){
            return false;
        }
        if(root->val!=temp->val) return false;
        bool leftfind=isfind(temp->next,root->left);
        bool rightfind=isfind(temp->next,root->right);

        if(leftfind || rightfind) return true;
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) return false;
        if(root->val==head->val){
            // cout<<root->val<<endl;
            if(isfind(head,root)==true){
                cout<<"Hello"<<endl;
                return true;
            }
        }
        bool left=isSubPath(head,root->left);
        bool right=isSubPath(head,root->right);

        if(left||right) return true;

        return false;
    }
};