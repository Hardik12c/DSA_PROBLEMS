class Solution {
public:
    int minpathsum(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &dp){
        if(j<0 || j>=matrix.size()){
            return 1e9;
        }
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=matrix[i][j]+minpathsum(matrix,i+1,j-1,dp);
        int mid=matrix[i][j]+minpathsum(matrix,i+1,j,dp);
        int right=matrix[i][j]+minpathsum(matrix,i+1,j+1,dp);

        return dp[i][j]=min(left,min(right,mid));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mn=INT_MAX;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
        for(int i=0;i<matrix.size();i++){
            mn=min(mn,minpathsum(matrix,0,i,dp));
        }
        return mn;
    }
};