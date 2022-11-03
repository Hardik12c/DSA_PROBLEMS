class Solution {
public:
    void remove(TreeNode* root,int target){
        if(root==NULL) return;
        remove(root->left,target);
        remove(root->right,target);
        if(root->left&&root->left->val==target){
            if(check(root->left)) root->left=NULL;
        }
        if(root->right && root->right->val==target){
            if(check(root->right)) root->right=NULL;
        }
    }
    bool check(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return true;
        else return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        remove(root,target);
        if(check(root)&&root->val==target) return NULL;
        return root;
    }
};