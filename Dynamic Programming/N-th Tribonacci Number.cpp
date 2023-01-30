class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==1 || n==2) return 1;
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int t_1=solve(n-3,dp);
        int t_2=solve(n-2,dp);
        int t_3=solve(n-1,dp);

        return dp[n]= t_1+t_2+t_3;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};