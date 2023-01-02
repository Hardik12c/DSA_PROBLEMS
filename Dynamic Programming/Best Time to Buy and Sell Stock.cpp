class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int mn=prices[0];
        int profit;
        for(int i=1;i<n;i++){
            profit=prices[i]-mn;
            maxprofit=max(maxprofit,profit);
            mn=min(mn,prices[i]);
        }
        return maxprofit;
    }
};