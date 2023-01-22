class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            int e=1e9;
            for(int j=1;j<=nums[i];j++){
                if(i+j<nums.size()){
                    int take=1+dp[i+j];
                    e=min(take,e);
                }
            }
            dp[i]=e;
        }
        return dp[0];
    }
};