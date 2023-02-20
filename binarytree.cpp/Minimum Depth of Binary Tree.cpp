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
    bool isleaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }
    int minH(TreeNode* root){
        if(root==NULL) return INT_MAX;
        if(isleaf(root)) return 1;
        int lh=minH(root->left);
        int rh=minH(root->right);
        return 1+min(lh,rh);  
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return minH(root);
    }
};
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(root==NULL) return 0;
//         int lh=minDepth(root->left);
//         int rh=minDepth(root->right);
//         if(lh==0) return 1+rh;
//         else return 1+lh;
//         return 1+min(lh,rh);  
//     }
// };