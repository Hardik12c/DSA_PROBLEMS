class Solution {
public:
    int check(int cnt,vector<vector<int>> board,int i,int j){
        if(cnt<2 && board[i][j]==1) return 0;
        else if((board[i][j]==1)&&(cnt==2 || cnt==3)) return 1;
        else if((board[i][j]==1)&&(cnt>3)) return 0;
        else if((board[i][j]==0)&&(cnt==3)) return 1;
        return board[i][j];
    }
    void count(int i,int j,int &count,vector<vector<int>> board){
        if(i-1>=0) count+=board[i-1][j];
        if(i+1<board.size()) count+=board[i+1][j];
        if(j+1<board[0].size()) count+=board[i][j+1];
        if(j-1>=0) count+=board[i][j-1];
        if(i-1>=0 && j-1>=0) count+=board[i-1][j-1];
        if(i+1<board.size() && j+1<board[0].size()) count+=board[i+1][j+1];
        if(i-1>=0 &&j+1<board[0].size()) count+=board[i-1][j+1];
        if(j-1>=0 && i+1<board.size()) count+=board[i+1][j-1];
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>>ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                count(i,j,cnt,board);
                ans[i][j]=check(cnt,board,i,j);
            }
        }
        board=ans;
    }
};
// more easy solution
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> col = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    if (i + row[k] >= 0 && i + row[k] < board.size() &&
                        j + col[k] >= 0 && j + col[k] < board[0].size()) {
                        count += temp[i + row[k]][j + col[k]];
                    }
                }
                if (count < 2 || count > 3) {
                    board[i][j] = 0;
                } else if (count == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};