class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long mx=INT_MIN;
        vector<long long> ans;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            mx=mx<nums[i]?nums[i]:mx;
            int conver=nums[i]+mx;
            sum+=conver;
            ans.push_back(sum);
        }
        return ans;
    }
};  