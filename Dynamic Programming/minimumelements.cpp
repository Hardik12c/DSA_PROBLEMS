#include <bits/stdc++.h> 
int solve(vector<int> &num,int x,int i,vector<vector<int>> &dp){
    if(x==0) return 0;
    if(i>=num.size()) return 1e9;
    if(dp[i][x]!=-1) return dp[i][x];
    int nottake=solve(num,x,i+1,dp);
    int take=1e9;
    if(num[i]<=x) take=1+solve(num,x-num[i],i,dp);
    
    return dp[i][x]= min(take,nottake);
}
int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>> dp(num.size()+1,vector<int>(x+1,-1));
    int ans =solve(num,x,0,dp);
    if(ans>=1e9) return -1;
    return ans;
}