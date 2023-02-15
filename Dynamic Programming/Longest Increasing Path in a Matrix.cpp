class Solution {
public:
    int solve(vector<vector<int>> &matrix,int row,int col,vector<vector<int>> &dp,vector<vector<int>>&vis){

        vis[row][col]=1;
        if(dp[row][col]!=-1) return dp[row][col];
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,-1,0,+1};
        int n=matrix.size();
        int m=matrix[0].size();
        
        int pathsize=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && matrix[nrow][ncol]>matrix[row][col]){
                int size=1+solve(matrix,nrow,ncol,dp,vis);
                pathsize=max(pathsize,size);
            }
        }
        return dp[row][col]=pathsize;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    int len=solve(matrix,i,j,dp,vis);
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};