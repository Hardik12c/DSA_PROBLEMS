class Solution {
public:
    int solve(int &k,vector<int> &arr,int i,vector<int> &dp){
        if(i==arr.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int mxnum=INT_MIN;
        int len=0;
        int mxans=INT_MIN;

        int n=arr.size();

        for(int j=i;j<min(n,i+k);j++){
            len++;
            mxnum=max(mxnum,arr[j]);
            int maxsum=(mxnum*len)+solve(k,arr,j+1,dp);
            mxans=max(mxans,maxsum);
        }
        return dp[i]=mxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(k,arr,0,dp);
    }
};