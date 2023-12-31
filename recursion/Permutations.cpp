class Solution {
public:
    void recurse(vector<vector<int>> &ans,vector<int> num, int ind,vector<int> nums){
        if(ind>=nums.size()){
            ans.push_back(num);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            num.push_back(nums[ind]);
            recurse(ans,num,ind+1,nums);
            num.pop_back();
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> num;
        recurse(ans,num,0,nums);
        return ans;
    }
};