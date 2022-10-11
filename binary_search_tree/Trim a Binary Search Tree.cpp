class Solution {
public:
    TreeNode* trimBST(TreeNode* &root, int low, int high) {
        if(root==NULL) return NULL;
        TreeNode* leftk= trimBST(root->left,low,high);
        TreeNode* rightk=trimBST(root->right,low,high);
        if(root->val<low || root->val>high) root=createnode(root);
        return root;
    }
    TreeNode* createnode(TreeNode* &root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* righroot=root->right;
        TreeNode* rootend=findrig(root->left);
        rootend->right=righroot;
        return root->left;
    }
    TreeNode* findrig(TreeNode* root){
        if(root->right==NULL) return root;
        return findrig(root->right);
    }

};