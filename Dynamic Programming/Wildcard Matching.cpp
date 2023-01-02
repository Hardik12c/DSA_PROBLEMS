class Solution {
public:
    bool recurse(string &s,string &p,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0) return true; 
        if(j<0 && i>=0) return false;
        if(j>=0 && i<0){
            for(int pointer=0;pointer<=j;pointer++){
                if(p[pointer]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=recurse(s,p,i-1,j-1,dp);
        }

        if(p[j]=='*'){
            return dp[i][j]=recurse(s,p,i,j-1,dp) | recurse(s,p,i-1,j,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recurse(s,p,n-1,m-1,dp);
    }
};