int solve(int n,vector<int> &height,vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int onestep=solve(n-1,height,dp)+abs(height[n]-height[n-1]);
        int doublestep=INT_MAX;
        if(n>1){
            doublestep=solve(n-2,height,dp)+abs(height[n]-height[n-2]);
        }
        
        return dp[n]=min(onestep,doublestep);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1,-1);
        return solve(n-1,height,dp);
    }