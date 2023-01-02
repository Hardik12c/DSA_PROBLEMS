class Solution {
public:
    int solve(int k,int i,int buy,int sell,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(buy==k && sell==k) return 0;
        if(i>=prices.size()) return 0;

        if(dp[i][buy][sell]!=-1) return dp[i][buy][sell];

        int profit;
        if(buy==sell){
            profit=max((0-prices[i])+solve(k,i+1,buy+1,sell,prices,dp),solve(k,i+1,buy,sell,prices,dp));
        }else{
            profit=max(prices[i]+solve(k,i+1,buy,sell+1,prices,dp),solve(k,i+1,buy,sell,prices,dp));
        }
        return dp[i][buy][sell]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k+1,vector<int>(k+1,-1)));
        return solve(k,0,0,0,prices,dp);
    }
};