class Solution {
public:
    void all(vector<vector<int>> &ans,vector<int> nums,int i){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            all(ans,nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int i=0;
        all(ans,nums,i);
        set<vector<int>> st;
        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }
        ans.clear();
        copy(st.begin(),st.end(),back_inserter(ans));
        return ans;
    }
};