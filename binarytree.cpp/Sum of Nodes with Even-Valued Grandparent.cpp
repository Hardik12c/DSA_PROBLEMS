class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> qu;
        unordered_map<TreeNode*,TreeNode*> mpp;
        int sum=0;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size(); 
            for(int i=0;i<n;i++){
                TreeNode* level=qu.front();
                qu.pop();
                if(level->left){
                    qu.push(level->left);
                    mpp[level->left]=level;
                }
                if(level->right){
                    qu.push(level->right);
                    mpp[level->right]=level;
                }
                if(mpp[mpp[level]] && (mpp[mpp[level]]->val)%2==0){
                    sum+=level->val;
                }
            }
        }
        return sum;
    }
};