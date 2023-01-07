class Solution {
public:
    int solve(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        int mn=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp);
            mn=min(mn,cost);
        }
        return dp[i][j]=mn;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return solve(1,c,cuts,dp);
    }
};