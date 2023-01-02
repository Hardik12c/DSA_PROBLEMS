class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        // if matching
        if(s[i]==t[j]){
            int take=solve(i-1,j-1,s,t,dp);
            int nottake=solve(i-1,j,s,t,dp);
            return dp[i][j]= take+nottake;
        }
        // not matching
        return dp[i][j]= solve(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        return solve(s.length()-1,t.length()-1,s,t,dp);
    }
};