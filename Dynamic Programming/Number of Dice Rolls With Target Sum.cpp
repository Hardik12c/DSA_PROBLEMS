class Solution {
public:
    int recurse(int n,int k,int target,vector<vector<int>> &dp){
        if(n==0){
            if(target==0) return 1;
            return 0;
        }
        if(dp[n][target]!=-1) return dp[n][target];
        int count=0;
        for(int i=1;i<=k;i++){
            if(i<=target){
                count+=recurse(n-1,k,target-i,dp);
                count%=1000000007;
            }
        }
        return dp[n][target]=count;

    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+2,vector<int>(1002,-1));
        return recurse(n,k,target,dp);
    }
};