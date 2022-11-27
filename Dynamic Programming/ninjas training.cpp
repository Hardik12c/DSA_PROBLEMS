int solve(int day,int lasttask,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==points.size()-1){
        int mx=0;
        for(int i=0;i<3;i++){
            if(i!=lasttask){
                mx=max(mx,points[day][i]);
            }
        }
        return mx;
    }
    if(dp[day][lasttask]!=-1) return dp[day][lasttask];
    int mx=0;
    for(int i=0;i<3;i++){
        if(i!=lasttask){
            mx=max(mx,points[day][i]+solve(day+1,i,points,dp));
        }
    }
    return dp[day][lasttask]= mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(0,3,points,dp);
}