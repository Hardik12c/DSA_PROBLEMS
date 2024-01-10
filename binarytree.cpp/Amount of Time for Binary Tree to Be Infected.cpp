class Solution {
public:
    void getparents(TreeNode* root ,unordered_map<TreeNode*,TreeNode*> &mpp){
        if(root==NULL){
            return;
        }
        if(root->left){
            mpp[root->left]=root;
            getparents(root->left,mpp);
        }
        if(root->right){
            mpp[root->right]=root;  
            getparents(root->right,mpp); 
        }
    }
    TreeNode* getNode(TreeNode* root,int start){
        if(root==NULL) return NULL;
        if(root->val==start) return root;
        TreeNode* left=getNode(root->left,start);
        TreeNode* right=getNode(root->right,start);
        if(left) return left;
        return right;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parents;
        getparents(root,parents);
        TreeNode* startNode=getNode(root,start);
        queue<TreeNode*> qu;
        qu.push(startNode);
        int ans=0;
        unordered_map<int,int> mpp;
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                TreeNode* node=qu.front();
                qu.pop();
                if(parents.find(node)!=parents.end()&& mpp.find(node->val)==mpp.end()){
                    qu.push(parents[node]);
                    mpp[node->val]=1;
                }
                if(node->left && mpp.find(node->left->val)==mpp.end()){
                    qu.push(node->left);
                    mpp[node->left->val]=1;
                }
                if(node->right && mpp.find(node->right->val)==mpp.end()){
                    qu.push(node->right);
                    mpp[node->right->val]=1;
                }
            }
            if(qu.size()>0) ans++;
        }
        return ans;
    }
};