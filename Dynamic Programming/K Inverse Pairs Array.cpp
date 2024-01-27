class Solution {
    int Mod=1e9+7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            long long sum=1;
            for(int j=1;j<=k;j++){
                sum+=dp[i-1][j];
                if(j>=i) sum-=dp[i-1][j-i];
                dp[i][j]=sum%Mod;
            }
        }
        return dp[n][k];
    }
};