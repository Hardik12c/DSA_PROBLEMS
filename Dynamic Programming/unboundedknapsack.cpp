#include <bits/stdc++.h> 
int solve(vector<int> &profit, vector<int> &weight,int i,int w,vector<vector<int>>&dp){
    if(i>=weight.size()) return 0;
    
    if(dp[i][w]!=-1) return dp[i][w];
    int nottake=solve(profit,weight,i+1,w,dp);
    int take=0;
    if(weight[i]<=w) take=profit[i]+solve(profit,weight,i,w-weight[i],dp);
    
    return dp[i][w]=max(take,nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return solve(profit,weight,0,w,dp);
}