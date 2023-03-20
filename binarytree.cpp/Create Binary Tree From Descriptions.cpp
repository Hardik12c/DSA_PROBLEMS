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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int>mppnum;
        unordered_map<int,TreeNode*> mpp;
        for(int i=0;i<descriptions.size();i++){
            int p=descriptions[i][0];
            int c=descriptions[i][1];
            TreeNode* parent;
            TreeNode* child;
            if(mpp.find(p)==mpp.end()){
                parent=new TreeNode(p);
                mpp[p]=parent;
            }else{
                parent=mpp[p];
            }
            if(mpp.find(c)==mpp.end()){
                child=new TreeNode(c);
                mpp[c]=child;
                mppnum[c]++;
            }
            else{
                child=mpp[c];
                mppnum[c]++;
            }
            if(descriptions[i][2]==1){
                parent->left=child;
            }else parent->right=child;
        }
        TreeNode* ans;
        for(int i=0;i<descriptions.size();i++){
            if(mppnum.find(descriptions[i][0])==mppnum.end()){
                ans=mpp[descriptions[i][0]];
                break;
            }
        }
        return ans;
    }
};