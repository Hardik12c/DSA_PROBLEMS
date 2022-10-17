class Solution {
public:
    void subsetsum(int ind,vector<int> nums,vector<vector<int>> &ans,vector<int> store){
        if(ind>=nums.size()) return;

        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;

            store.push_back(nums[i]);
            ans.push_back(store);
            subsetsum(i+1,nums,ans,store);
            store.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ind=0;
        vector<vector<int>> ans;
        vector<int> store;
        ans.push_back(store);
        subsetsum(ind,nums,ans,store);
        return ans;
    }
};