class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> board){
        vis[i][j]=1;
        if(i-1>=0 && !vis[i-1][j] && board[i-1][j]=='O'){
            dfs(i-1,j,vis,board);
        }        
        if(i+1<board.size() && !vis[i+1][j] && board[i+1][j]=='O'){
            dfs(i+1,j,vis,board);
        }
        if(j-1>=0&& !vis[i][j-1] && board[i][j-1]=='O'){
            dfs(i,j-1,vis,board);
        }
        if(j+1<board[0].size() && !vis[i][j+1] && board[i][j+1]=='O'){
            dfs(i,j+1,vis,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] &&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};