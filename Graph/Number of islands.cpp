class Solution {
public:
    void bfs(vector<vector<char>> grid, vector<vector<int>> &isvisited,int i,int j){
        queue<pair<int,int>> qu;
        qu.push({i,j});
        isvisited[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        while(!qu.empty()){
            int row=qu.front().first;
            int col=qu.front().second;
            qu.pop();
            if(row-1>=0 && grid[row-1][col]!='0' && !isvisited[row-1][col]){
                qu.push({row-1,col});
                isvisited[row-1][col]=1;
            }
            if(col-1>=0 && grid[row][col-1]!='0' && !isvisited[row][col-1]){
                qu.push({row,col-1});
                isvisited[row][col-1]=1;
            }
            if(row+1<n && grid[row+1][col]!='0' && !isvisited[row+1][col]){
                qu.push({row+1,col});
                isvisited[row+1][col]=1;
            }
            if(col+1<m && grid[row][col+1]!='0' && !isvisited[row][col+1]){
                qu.push({row,col+1});
                isvisited[row][col+1]=1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> isvisited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !isvisited[i][j]){
                    bfs(grid,isvisited,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};