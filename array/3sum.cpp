class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]){
                int s=i+1;
                int e=nums.size()-1;
                int find=0-nums[i];
                while(s<e){
                    if(nums[s]+nums[e]==find){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[e]);
                        ans.push_back(temp);
                        while(s<e && nums[s]==nums[s+1]) s++;
                        while(s<e && nums[e]==nums[e-1]) e--;
                        s++; e--;
                    }else if(nums[s]+nums[e]<find){
                        s++;
                    }else{
                        e--;
                    }                    
                }
            }
        }
        return ans;
    }
};