class Solution {
public:
    int findcosts(vector<int> &costs,vector<int> &days,int i,int daynum,vector<vector<int>> &dp){
        if(i>=days.size()) return 0;
        if(dp[i][daynum]!=-1) return dp[i][daynum];
        if(daynum<days[i]){
            int oneday=costs[0]+findcosts(costs,days,i+1,days[i],dp);
            int sevennumday=min(365,days[i]+6);
            int sevenday=costs[1]+findcosts(costs,days,i+1,sevennumday,dp);
            int thirtynumdays=min(365,days[i]+29);
            int thirtydays=costs[2]+findcosts(costs,days,i+1,thirtynumdays,dp);
            return dp[i][daynum]=min(oneday,min(sevenday,thirtydays));
        }
        return dp[i][daynum]=findcosts(costs,days,i+1,daynum,dp);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(),vector<int>(366,-1));
        return findcosts(costs,days,0,0,dp);
    }
};