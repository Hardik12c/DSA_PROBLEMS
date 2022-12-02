class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()){
            return -1e9;
        }
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int mx=INT_MIN;
        // exploring all the paths
        for(int rob1=-1;rob1<=1;rob1++){
            for(int rob2=-1;rob2<=1;rob2++){
                int value=0;
                if(j1==j2) value+=grid[i][j1];
                else value+=grid[i][j1]+grid[i][j2];
                value+=solve(i+1,j1+rob1,j2+rob2,grid,dp);
                mx=max(mx,value);
            }
        }
        return dp[i][j1][j2]= mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return solve(0,0,grid[0].size()-1,grid,dp);
    }
};