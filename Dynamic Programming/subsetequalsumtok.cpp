#include <bits/stdc++.h>
bool solve(int i,int n,int k,vector<int>&arr,vector<vector<int>> &dp){
    if(k==0) return true;
    if(i==n) return k==arr[n];
    if(dp[i][k]!=-1) return dp[i][k];
    bool take=false;
    if(k>=arr[i]) take=solve(i+1,n,k-arr[i],arr,dp);
    bool nottake=solve(i+1,n,k,arr,dp);
    
    return dp[i][k]=take||nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return solve(0,n-1,k,arr,dp);
}