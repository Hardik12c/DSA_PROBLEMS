class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> mpp; //for storing postorder mapping
        for(int i=0;i<postorder.size();i++){
            mpp[postorder[i]]=i;
        }
        return buildtree(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1,mpp);
    }
    TreeNode* buildtree(vector<int> preorder, vector<int> postorder,int prest,int preend,int postst,int postend,unordered_map<int,int> mpp){
        if(prest>preend || postst>postend) return NULL;

        TreeNode* root=new TreeNode(preorder[prest]);

        if(prest+1<=preend){
            int find=mpp[preorder[prest+1]];
            int diff=find-postst;
            root->left=buildtree(preorder,postorder,prest+1,prest+1+diff,postst,find,mpp);
            root->right=buildtree(preorder,postorder,prest+diff+2,preend,find+1,postend-1,mpp);
        }
        return root;
    }
};