class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
        vis[i][j]=1;
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
            dfs(i-1,j,vis,grid);
        }        
        if(i+1<grid.size() && !vis[i+1][j] && grid[i+1][j]==1){
            dfs(i+1,j,vis,grid);
        }
        if(j-1>=0&& !vis[i][j-1] && grid[i][j-1]==1){
            dfs(i,j-1,vis,grid);
        }
        if(j+1<grid[0].size() && !vis[i][j+1] && grid[i][j+1]==1){
            dfs(i,j+1,vis,grid);
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,vis,grid);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;

    }
};