/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        unordered_map<int,int> mpp;
        while(!qu.empty()){
            int n=qu.size();

            for(int i=0;i<n;i++){
                TreeNode* node=qu.front();
                qu.pop();
                mpp[node->val]++;
                if(node->left){
                    qu.push(node->left);
                }    
                if(node->right){
                    qu.push(node->right);
                }
            }
        }
        int num=INT_MIN;
        for(auto e:mpp){
            int first=e.first;
            int second=e.second;
            if(second>num){
                vector<int> newans;
                ans=newans;
                num=second;
                ans.push_back(first);
            }else if(second==num){
                ans.push_back(first);
            }
        }
        return ans;
    }
};