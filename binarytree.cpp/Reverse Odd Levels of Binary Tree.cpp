class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int count=0;
        while(!qu.empty()){
            int n=qu.size();
            vector<TreeNode*> v;
            for(int i=0;i<n;i++){
                TreeNode* level=qu.front();
                qu.pop();
                if(count&1) v.push_back(level);
                if(level->left) qu.push(level->left);
                if(level->right) qu.push(level->right);
            }
            if(count&1){
                int s=0;int e=v.size()-1;
                while(s<e){
                    swap(v[s]->val,v[e]->val);
                    s++;e--;
                }
            }
            count++;
        }
        return root;
    }
};