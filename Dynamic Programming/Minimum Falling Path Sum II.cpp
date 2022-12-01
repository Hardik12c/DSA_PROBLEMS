class Solution {
public:
    int minsum(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        if(i==grid.size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=INT_MAX;
        for(int col=0;col<grid.size();col++){
            if(col!=j){
                int f=grid[i][j]+minsum(grid,i+1,col,dp);
                mn=min(mn,f);
            } 
        }
        return dp[i][j]=mn;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int mn=INT_MAX;
        vector<vector<int>> dp(grid.size(),vector<int>(grid.size(),-1));
        for(int i=0;i<grid.size();i++){
            mn=min(mn,minsum(grid,0,i,dp));
        }
        return mn;
    }
};