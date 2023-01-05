class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int len=0;
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        int lastindex=0;
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(1+dp[j]>dp[i]&&nums[i]%nums[j]==0){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>len){
                len=dp[i];
                lastindex=i;
            }
        }
        vector<int> ans;
        while(lastindex!=hash[lastindex]){
            ans.push_back(nums[lastindex]);
            lastindex=hash[lastindex];
        }
        ans.push_back(nums[lastindex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};