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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> qu;
        qu.push(root);
        priority_queue<long long> pq;
        while(!qu.empty()){
            long long sum=0;
            int n=qu.size();
            for(int i=0;i<n;i++){
                TreeNode* num=qu.front();
                qu.pop();
                sum+=num->val;
                if(num->left) qu.push(num->left);
                if(num->right) qu.push(num->right);
            }
            pq.push(sum);
        }
        while(!pq.empty()){
            if(k==1) return pq.top();
            k--;
            // cout<<pq.top()<<endl;
            pq.pop();
        }
        return -1;
    }
};