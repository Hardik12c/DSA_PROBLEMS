class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first;
        TreeNode* last;
        TreeNode* middle;
        first=middle=last=NULL;
        TreeNode* prev=new TreeNode(INT_MIN);
        update(root,prev,first,middle,last);
        if(first&&last) swap(first->val,last->val);
        else swap(middle->val,first->val);
    }
    void update(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &middle,TreeNode* &last){
        if(root==NULL) return;
        update(root->left,prev,first,middle,last);
        if(root->val<prev->val){
            if(first==NULL){
                first=prev;
                middle=root;
            } 
            else last=root;
        }
        prev=root;
        update(root->right,prev,first,middle,last);
    }
};