class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
            if(mpp[nums[i]].size()>1){
                for(int j=0;j<mpp[nums[i]].size()-1;j++){
                    if(abs(i-(mpp[nums[i]][j]))<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};