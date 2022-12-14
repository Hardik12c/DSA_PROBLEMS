class Solution {
public:
    int maxcommonseq(string &a,string &b,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]) return dp[i][j]= 1+maxcommonseq(a,b,i-1,j-1,dp);

        return dp[i][j]= max(maxcommonseq(a,b,i-1,j,dp),maxcommonseq(a,b,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        return maxcommonseq(text1,text2,text1.length()-1,text2.length()-1,dp);
    }
};