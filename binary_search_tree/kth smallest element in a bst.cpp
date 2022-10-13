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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans;
        smallest(root,k,cnt,ans);
        return ans;
    }
    void smallest(TreeNode* root,int k,int &cnt,int &ans){
        if(root==NULL) return;
        smallest(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
        }
        smallest(root->right,k,cnt,ans);
    }
};