class Solution {
public:
    int solve(vector<int> &prices,int i,int buy,vector<vector<int>> &dp,int fee){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy){
            profit=max((0-prices[i])+solve(prices,i+1,0,dp,fee),solve(prices,i+1,1,dp,fee));
        }else{
            profit=max(prices[i]+solve(prices,i+1,1,dp,fee)-fee,solve(prices,i+1,0,dp,fee));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,dp,fee);
    }
};