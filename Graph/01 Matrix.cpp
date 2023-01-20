class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m));

        queue<pair<pair<int,int>,int>> qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    qu.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!qu.empty()){
            int row=qu.front().first.first;
            int col=qu.front().first.second;
            int steps=qu.front().second;
            qu.pop();
            dis[row][col]=steps;

            if(row-1>=0 && !vis[row-1][col]){
                vis[row-1][col]=1;
                qu.push({{row-1,col},steps+1});
            }
            if(row+1<n && !vis[row+1][col]){
                vis[row+1][col]=1;
                qu.push({{row+1,col},steps+1});
            }
            if(col-1>=0 && !vis[row][col-1]){
                vis[row][col-1]=1;
                qu.push({{row,col-1},steps+1});
            }
            if(col+1<m && !vis[row][col+1]){
                vis[row][col+1]=1;
                qu.push({{row,col+1},steps+1});
            }
        }
        return dis;
    }
};