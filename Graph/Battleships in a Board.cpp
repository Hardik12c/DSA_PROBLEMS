class Solution {
public:
    void dfs(vector<vector<char>> board,vector<vector<int>> &vis,int i,int j){
        vis[i][j]=1;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,-1,0,+1};

        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]=='X' && !vis[nrow][ncol]){
                dfs(board,vis,nrow,ncol);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int cnt=0;
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    dfs(board,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;

    }
};