class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1) ans.push_back(nums[i]);
        }
        for(int i=1;i<=nums.size();i++){
            if(mpp[i]==0){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};