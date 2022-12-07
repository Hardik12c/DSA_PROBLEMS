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
    void findsum(TreeNode* root,int low,int high,int &sum){
        if(root==NULL) return ;
        if(root->val>=low && root->val<=high) sum+=root->val;

        if(root->val>=low) findsum(root->left,low,high,sum);

        if(root->val<=high) findsum(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        findsum(root,low,high,sum);
        return sum;
    }
};