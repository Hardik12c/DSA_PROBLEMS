class Solution {
public:
    int countnodes(TreeNode* root){
        if(root==NULL) return 0;

        return 1+countnodes(root->left)+countnodes(root->right);
    }
    bool isCBT(TreeNode* root,int i,int nodes){
        if(root==NULL) return true;
        
        if(i>=nodes) return false;
        return isCBT(root->left,2*i+1,nodes) && isCBT(root->right,2*i+2,nodes);
    }
    bool isCompleteTree(TreeNode* root) {
        int nodes=countnodes(root);
        return isCBT(root,0,nodes);
    }
};