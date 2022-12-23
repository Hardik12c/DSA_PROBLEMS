class Solution {
public:
    int solve(vector<int> &arr,int i,int sum,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(i>=arr.size() || sum<0) return 0;


        if(dp[i][sum]!=-1) return dp[i][sum];
        // take not take approach

        int nottake=solve(arr,i+1,sum,dp);

        int take=0;
        if(arr[i]<=sum){
            take=solve(arr,i,sum-arr[i],dp);
        }
        return dp[i][sum]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int k=solve(coins,0,amount,dp);
        return k;
    }
};