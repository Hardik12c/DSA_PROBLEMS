class Solution {
public:
    vector<int> help(int idx, vector<int> &nums, vector<vector<int>> &dp){
        int n = size(nums);
        if(idx == n) return {};
        if(dp[idx].size()!=0)return dp[idx]; 

        vector<int> ans;
        for(int i=idx+1;i<n;i++){
            if(nums[i] % nums[idx] == 0){
                vector<int> res = help(i, nums, dp);
                if(res.size() > size(ans)) ans = res;
            }
        }
        ans.push_back(nums[idx]);
        return dp[idx] = ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;++i){
            vector<vector<int>> dp(n);
            vector<int> res;
            res = help(i,nums,dp);
            if(res.size() >= ans.size()) ans = res;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};