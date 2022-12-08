class Solution {
public:
    void findleaves(TreeNode* root,vector<int> &arr){
        if(root==NULL) return ;
        if(root->right==NULL && root->left==NULL) arr.push_back(root->val);

        findleaves(root->left,arr);
        findleaves(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2;
        findleaves(root1,arr1);
        findleaves(root2,arr2);
        if(arr1!=arr2) return false;
        return true;
    }
};