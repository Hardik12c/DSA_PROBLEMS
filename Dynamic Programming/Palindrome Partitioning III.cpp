class Solution {
public:
    int check(string &s,int i,int j){
        int change=0;
        while(i<j){
            if(s[i]!=s[j]) change++;
            i++;j--;
        }
        return change;
    }
    int solve(string &s,int i,int k, vector<vector<int>> &dp){
        if(i>s.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==1) return check(s,i,s.size()-1);  // as k remains 1 we cannot do further more partitions


        int change=INT_MAX;
        for(int j=i;j<s.size()-k+1;j++){   // we are doing +1 because we have already included one partition so we have to decrease k
            int mn=check(s,i,j)+solve(s,j+1,k-1,dp);
            change=min(mn,change);
        }
        return dp[i][k]=change;
    }
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size(),vector<int>(k+1,-1));
        return solve(s,0,k,dp);
        return 0;
    }
};