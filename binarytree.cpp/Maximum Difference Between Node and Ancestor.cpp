class Solution {
public:
    void maxdiff(TreeNode* root,int &ans,vector<TreeNode*> store){
        if(root==NULL) return;
        // first step checking for differences of ancestors
        for(int i=0;i<store.size();i++){
            ans=max(ans,abs(store[i]->val-root->val));
        }
        // second step storing the node for next upcoming nodes
        store.push_back(root);
        maxdiff(root->left,ans,store);
        maxdiff(root->right,ans,store);
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<TreeNode*> store;
        int ans=INT_MIN;
        maxdiff(root,ans,store);
        return ans;
    }
};

// second approach
class Solution {
public:
    void maxdiff(TreeNode* root,int &ans,int mx,int mn){
        if(root==NULL) {
            ans=max(ans,mx-mn);
            return;
        }
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        maxdiff(root->left,ans,mx,mn);
        maxdiff(root->right,ans,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        int ans=INT_MIN;
        maxdiff(root,ans,mx,mn);
        return ans;
    }
};