class Solution {
public:
    int recurse(vector<int> &difficult,int d,int ind,vector<vector<int>> &dp){
        if(dp[ind][d]!=-1) return dp[ind][d];
        if(d==1){
            int mx=INT_MIN;
            for(int i=ind;i<difficult.size();i++){
                mx=max(difficult[i],mx);
            }
            if(mx==INT_MIN) return dp[ind][d]= INT_MAX;
            return dp[ind][d]=mx;
        }
        int num=INT_MIN;
        int sum=INT_MAX;
        for(int i=ind;i<difficult.size();i++){
            num=max(num,difficult[i]);
            int rec=recurse(difficult,d-1,i+1,dp);
            if(rec!=INT_MAX) sum=min(sum,(num+rec));
        }
        return dp[ind][d]=sum;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>> dp(jobDifficulty.size()+2,vector<int>(d+2,-1));
        if(jobDifficulty.size()<d) return -1;
        return recurse(jobDifficulty,d,0,dp);
    }
};