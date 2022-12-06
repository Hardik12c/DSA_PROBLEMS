class Solution {
public:
    bool solve(int n,int i,vector<int> &nums,int sum,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(i==n) return nums[i]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take=false;
        if(sum>=nums[i]) take=solve(n,i+1,nums,sum-nums[i],dp);
        bool nottake=solve(n,i+1,nums,sum,dp);
        return dp[i][sum]= take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n=nums.size()-1;
        if(sum&1) return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return solve(n,0,nums,sum/2,dp);
    }
};