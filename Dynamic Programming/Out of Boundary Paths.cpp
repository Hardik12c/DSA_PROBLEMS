class Solution {
public:
    int recurse(int &m,int &n,int maxMove,int row,int col,vector<vector<vector<int>>> &dp){
        if(maxMove<0) return 0;
        if(row<0 || col<0 || row>=m || col>=n){
            return 1;
        }
        if(dp[row][col][maxMove]!=-1) return dp[row][col][maxMove];
        int left=(recurse(m,n,maxMove-1,row,col-1,dp)%1000000007);
        int right=(recurse(m,n,maxMove-1,row,col+1,dp)%1000000007);
        int top=(recurse(m,n,maxMove-1,row+1,col,dp)%1000000007);
        int bottom=(recurse(m,n,maxMove-1,row-1,col,dp)%1000000007);

        return dp[row][col][maxMove]=(((left+right)%1000000007)+((top+bottom)%1000000007))%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return recurse(m,n,maxMove,startRow,startColumn,dp);
    }
};