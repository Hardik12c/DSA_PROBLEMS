class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>> &grid,vector<pair<int,int>> &vec,vector<vector<int>> &vis,int row,int col){
        vis[row][col]=1;
        vec.push_back({row-i,col-j});
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,-1,0,+1};
        
        for(int n=0;n<4;n++){
            int nrow=row+delrow[n];
            int ncol=col+delcol[n];
            
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(i,j,grid,vec,vis,nrow,ncol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> st;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vec,vis,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};