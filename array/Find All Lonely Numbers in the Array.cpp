class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
       unordered_map<int,int> mpp;
       for(int i=0;i<nums.size();i++){
           mpp[nums[i]-1]++;
           mpp[nums[i]+1]++;
           mpp[nums[i]]++;
       }
       vector<int> ans; 
       for(int i=0;i<nums.size();i++){
           if(mpp[nums[i]]==1){
               ans.push_back(nums[i]);
           }
       }
       return ans;
    }
};