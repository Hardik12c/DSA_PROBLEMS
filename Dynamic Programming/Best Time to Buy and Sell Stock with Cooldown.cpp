class Solution {
public:
    int solve(vector<int> &prices,int i,int buy,vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy){
            profit=max((0-prices[i])+solve(prices,i+1,0,dp),solve(prices,i+1,1,dp));
        }else{
            profit=max(prices[i]+solve(prices,i+2,1,dp),solve(prices,i+1,0,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};