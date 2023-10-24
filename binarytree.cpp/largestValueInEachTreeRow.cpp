class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> ans;
        if(root==NULL) return ans;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            int highest=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* level=qu.front();
                highest=max(highest,level->val);
                qu.pop();
                if(level->left){
                    qu.push(level->left);
                }
                if(level->right){
                    qu.push(level->right);
                }
            }
            ans.push_back(highest);
        }
        return ans;
    }
};