class Solution {
public:
    int solve(vector<int> &arr,int sum,vector<int> &dp){
        if(sum<0) return 1e9;
        if(sum==0){
            return 0;
        } 
        if(dp[sum]!=-1) return dp[sum];
        int k=INT_MAX;
        for(int j=0;j<arr.size();j++){
            int l=1+solve(arr,sum-arr[j],dp);
            k=min(k,l);
        }
        return dp[sum]=k;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans= solve(coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};