class Solution {
public:
    int solve(string &word1,string &word2,int i,int j,vector<vector<int>> &dp){
        // adding one to both because its zero based indexing
        if(i<0) return 1+j;
        if(j<0) return 1+i;

        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(word1,word2,i-1,j-1,dp);
        }

        return dp[i][j]=1+min(solve(word1,word2,i,j-1,dp),min(solve(word1,word2,i-1,j,dp),solve(word1,word2,i-1,j-1,dp)));  //adding plus one here because we are performing an operation so counting that
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};