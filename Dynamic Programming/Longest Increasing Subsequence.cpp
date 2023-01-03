class Solution {
public:
    int solve(int prev,int i,vector<int>& nums,vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        // take not take approach
        int take=INT_MIN;
        if(prev==-1 || nums[i]>nums[prev]){
            take=1+solve(i,i+1,nums,dp);
        }
        int nottake=solve(prev,i+1,nums,dp);
        return dp[i][prev+1]= max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(-1,0,nums,dp);
    }
};