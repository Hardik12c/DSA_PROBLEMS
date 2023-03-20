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
    void preorder(TreeNode* root,string s,string &ans){
        if(root==NULL) return;
        s+=(root->val+'a');
        preorder(root->left,s,ans);
        preorder(root->right,s,ans);
        if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            ans=min(ans,s);
            return;
        }
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        preorder(root,"",ans);
        return ans;
    }
};