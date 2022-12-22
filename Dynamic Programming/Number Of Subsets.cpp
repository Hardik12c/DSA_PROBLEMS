#include <bits/stdc++.h> 
int solve(vector<int> nums,int target,int i,vector<vector<int>> &dp){
    if(i>=nums.size()){
        if(target==0){
            return (target==0);
        }
        return 0;
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int takep=0;
    if(nums[i]<=target) takep=solve(nums,target-nums[i],i+1,dp);
    int taken=solve(nums,target,i+1,dp);
    return dp[i][target]=takep+taken;
}
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size()+1,vector<int>(tar+1,-1));
    return solve(num,tar,0,dp);
}