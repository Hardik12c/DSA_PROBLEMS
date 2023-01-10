class Solution{
public:
    int solve(int arr[],int N,int i,int j,vector<vector<int>> &dp){
        if(i==j) return 0;
        int mn=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i+1;k<=j;k++){
            int operations=arr[i-1]*arr[k-1]*arr[j]+solve(arr,N,i,k-1,dp)+solve(arr,N,k,j,dp);
            mn=min(operations,mn);
        }
        
        return dp[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return solve(arr,N,1,N-1,dp);
        // code here
    }
};
