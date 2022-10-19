class Solution {
public:
    int maxelement(int s,int e,vector<int> nums){
        int mxindex;
        int mx=INT_MIN;
        for(int i=s;i<=e;i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxindex=i;
            }
        }
        return mxindex;
    }
    TreeNode* construct(vector<int> arr,int s,int e){
        if(s>e){
            return NULL;
        }
        int maxi=maxelement(s,e,arr);
        TreeNode* root=new TreeNode(arr[maxi]);
        root->left=construct(arr,s,maxi-1);
        root->right=construct(arr,maxi+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        return construct(nums,s,e);
    }
};