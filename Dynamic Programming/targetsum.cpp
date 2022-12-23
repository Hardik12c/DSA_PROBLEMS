class Solution {
public:
    int solve(vector<int> nums,int target,int i,vector<vector<int>> &dp){
        if(i>=nums.size()){
            return (target==0);
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int nottake=solve(nums,target,i+1,dp);
        int take=0;
        if(nums[i]<=target) take=solve(nums,target-nums[i],i+1,dp);
        return dp[i][target]=(nottake+take);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<n;i++){
            k+=nums[i];
        }
        if((k-target)&1 || (k-target)<0) return 0;
        int sum=(k-target)/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(nums,sum,0,dp);
        // return 0;
    }
};