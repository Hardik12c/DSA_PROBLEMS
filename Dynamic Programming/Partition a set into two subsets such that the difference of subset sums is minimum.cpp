#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalsum=0;
    for(int i=0;i<arr.size();i++){
        totalsum+=arr[i];
    }
    int k=totalsum;
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(arr[0]<=k) dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool nottake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j) take=dp[i-1][j-arr[i]];
            dp[i][j]=take|nottake;
        }
    }
    int mn=INT_MAX;
    
    for(int i=0;i<=totalsum/2;i++){
        if(dp[n-1][i]==true){
            mn=min(mn,abs((totalsum-i)-i));
        }
    }
    return mn;
}
