#include <bits/stdc++.h> 
int solve(vector<int> &weight,int i,int maxweight,vector<int> &value,vector<vector<int>> &dp){
    if(i>=weight.size()) return 0;
    
    if(dp[i][maxweight]!=-1) return dp[i][maxweight];
    int take=INT_MIN;
    if(weight[i]<=maxweight) take=value[i]+solve(weight,i+1,maxweight-weight[i],value,dp);
    int nottake=solve(weight,i+1,maxweight,value,dp);
    
    return dp[i][maxweight]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,-1));
	return solve(weight,0,maxWeight,value,dp);
}