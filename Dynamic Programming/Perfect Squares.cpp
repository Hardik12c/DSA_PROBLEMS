class Solution {
public:
    int recurse(int i,int n, vector<int> &sq,vector<vector<int>> &dp){
        if(n==0) return 0;
        if(n<0 || i>=sq.size()) return 1e5;
        if(dp[n][i]!=-1) return dp[n][i];
        int take=1+recurse(i,n-sq[i],sq,dp);
        int nottake=recurse(i+1,n,sq,dp);
        return dp[n][i]=min(take,nottake);
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i=1;i<101;i++){
            sq.push_back(i*i);
        }
        vector<vector<int>> dp(n+1,vector<int>(sq.size()+1,-1));
        return recurse(0,n,sq,dp);
    }
};