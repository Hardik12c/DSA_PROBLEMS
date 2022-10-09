class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertIntobst(root,val);
        return root;
    }
    void insertIntobst(TreeNode* &root,int val){
        if(root==NULL){
            root=new TreeNode(val);
            return;
        }
        if(root->val<val) insertIntobst(root->right,val);
        if(root->val>val) insertIntobst(root->left,val);
    }
};