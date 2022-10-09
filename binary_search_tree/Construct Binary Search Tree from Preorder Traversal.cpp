class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int st=0;int end=preorder.size()-1;
        TreeNode* ans=buildtree(preorder,st,end);
        return ans;
    }
    TreeNode* buildtree(vector<int> &preorder,int st,int end){
        if(st>end) return NULL;

        TreeNode* root=new TreeNode(preorder[st]);
        int count=0;
        for(int i=st+1;i<=end;i++){
            if(preorder[i]>preorder[st]) break;
            count++;
        }
        root->left=buildtree(preorder,st+1,st+count);
        root->right=buildtree(preorder,st+count+1,end);
        return root;
    }
};