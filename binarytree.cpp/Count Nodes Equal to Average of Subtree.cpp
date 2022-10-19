class sumcou{
    public:
    int sum;
    int count;
};
class Solution {
public:
    sumcou postorder(TreeNode* root,int &ans){
        if(root==NULL) return {0,0};

        sumcou lefta=postorder(root->left,ans);
        sumcou righta=postorder(root->right,ans);

        sumcou check;
        check.count=lefta.count+righta.count+1;
        check.sum=lefta.sum+righta.sum+root->val;

        if(((check.sum)/check.count)==root->val){
            ans++;
        }
        return check;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        postorder(root,ans);
        return ans;
    }
};