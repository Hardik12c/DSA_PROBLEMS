class Solution {
public:
    int solve(int n,vector<char> &v,string s,int i,vector<vector<int>> &dp){
        if(s.length()>n) return 0;
        if(s.length()==n) return 1;
        int k=s.length();
        if(dp[k][i]!=-1) return dp[s.length()][i];
        int total=0;
        for(int j=i;j<v.size();j++){
            s+=v[i];
            int take=solve(n,v,s,j,dp);

            s.pop_back();
            total+=take;
        }
        return dp[s.length()][i]=total;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5,-1));
        vector<char> v={'a','e','i','o','u'};
        return solve(n,v,"",0,dp);
    }
};