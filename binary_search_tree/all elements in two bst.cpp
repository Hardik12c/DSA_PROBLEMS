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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> first,second,ans;
        getinorder(root1,first);
        getinorder(root2,second);
        int i=0;int j=0;
        while(i<first.size() && j<second.size()){
            if(first[i]<second[j]){
                ans.push_back(first[i]);
                i++;
            }else{
                ans.push_back(second[j]);
                j++;
            }
        }
        while(i<first.size()){
            ans.push_back(first[i]);i++;
        }
        
        while(j<second.size()){
            ans.push_back(second[j]);j++;
        }
        return ans;
    }
    void getinorder(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;

        getinorder(root->left,ans);
        ans.push_back(root->val);
        getinorder(root->right,ans);
    }
};