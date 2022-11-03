class Solution {
public:
    bool pruning(TreeNode* &root){
        if(root==NULL) return false;
        bool leftans=pruning(root->left);
        bool rightans=pruning(root->right);
        if(leftans && rightans){
            return true;
        }else if(leftans==true && rightans==false){
            root->right=NULL;
            return true;
        }else if(leftans==false && rightans==true){
            root->left=NULL;
            return true;
        }
        root->left=NULL;
        root->right=NULL;
        if(root->val==1) return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool pur=pruning(root);
        if(!pur) return NULL;
        return root;
    }
};