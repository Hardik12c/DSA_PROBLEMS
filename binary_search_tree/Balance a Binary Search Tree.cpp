class Solution {
public:
    void getinorder(vector<int> &in,TreeNode* root){
        if(root==NULL) return;
        getinorder(in,root->left);
        in.push_back(root->val);
        getinorder(in,root->right);
    }
    TreeNode* formtree(int s,int e,vector<int> in){
        if(s>e) return NULL;
        
        int mid=s+(e-s)/2;

        TreeNode* newnode=new TreeNode(in[mid]);
        newnode->left=formtree(s,mid-1,in);
        newnode->right=formtree(mid+1,e,in);
        return newnode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        getinorder(in,root);
        return formtree(0,in.size()-1,in);
    }
};