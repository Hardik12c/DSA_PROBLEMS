class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        update(root,sum);
        return root;
    }
    void update(TreeNode* root,int &sum){
        if(root==NULL) return;

        update(root->right,sum);
        sum+=root->val;
        root->val=sum;
        update(root->left,sum);
    }
};