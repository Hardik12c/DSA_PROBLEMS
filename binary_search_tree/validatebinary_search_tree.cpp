class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isbst(root,LONG_MIN,LONG_MAX);
    }
    bool isbst(TreeNode* root,long mn,long mx){
        if(root==NULL) return true;
        if(root->val<=mn || root->val>=mx) return false;
        
        bool leftans=isbst(root->left,mn,root->val);
        bool rightans=isbst(root->right,root->val,mx);
        if(leftans && rightans) return true;
        return false;
    }
};