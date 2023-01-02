class Solution {
public:
    int solve(vector<int> &prices,int i,int buy,int sell,vector<vector<vector<int>>> &dp){
        if(buy==2 && sell==2) return 0;
        if(i>=prices.size()) return 0;
        if(dp[i][buy][sell]!=-1) return dp[i][buy][sell];
        int profit;
        if((buy==0&& sell==0) || (sell==1 && buy==1)){
            profit=max((0-prices[i])+solve(prices,i+1,buy+1,sell,dp),solve(prices,i+1,buy,sell,dp));
        }else{
            profit=max(prices[i]+solve(prices,i+1,buy,sell+1,dp),solve(prices,i+1,buy,sell,dp));
        }
        return dp[i][buy][sell]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(prices,0,0,0,dp);
    }
};