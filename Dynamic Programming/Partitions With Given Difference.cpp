#include <bits/stdc++.h> 
int mod=(int)(1e9+7);
int count(vector<int> &arr,int d,int i,vector<vector<int>> &dp){
    if(i>=arr.size()){
        return (d==0);
    }
    if(dp[i][d]!=-1) return dp[i][d];
    int take=0;
    if(arr[i]<=d){
        take=count(arr,d-arr[i],i+1,dp);
    }
    int nottake=count(arr,d,i+1,dp);
    return dp[i][d]=(take+nottake)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }    
    if((totalsum-d)&1 || (totalsum-d)<0) return 0;
    int s=(totalsum-d)/2;
    
    vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
    return count(arr,s,0,dp);
}


