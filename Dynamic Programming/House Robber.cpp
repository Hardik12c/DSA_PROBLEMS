class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=nums[0];int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=prev1;
            int curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

//memoization
class Solution {
public:
    int recurse(vector<int> &nums,int ind,vector<int> &dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        //take
        int take=nums[ind]+recurse(nums,ind+2,dp);
        int nottake=recurse(nums,ind+1,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return recurse(nums,0,dp);
    }
};