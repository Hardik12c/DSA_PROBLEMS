// recursive
#include <bits/stdc++.h>
int picknotpick(int i,vector<int> nums){
    if(i>=nums.size()) return 0;
    
    int pick=nums[i]+picknotpick(i+2,nums);
    int notpick=picknotpick(i+1,nums);
    
    return max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    return picknotpick(0,nums);
}
// memoization
#include <bits/stdc++.h>
int picknotpick(int i,vector<int> nums,vector<int> &dp){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int pick=nums[i]+picknotpick(i+2,nums,dp);
    int notpick=picknotpick(i+1,nums,dp);
    
    return dp[i]= max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1,-1);
    return picknotpick(0,nums,dp);
}
// tabulation with space optimised
#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1,-1);
    int prev1=nums[0]; int prev2=0;
    for(int i=1;i<nums.size();i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        int nontake=prev1;
        int curr=max(nontake,take);
        prev2=prev1;prev1=curr;
    }
    return prev1;
}