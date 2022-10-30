class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> supportingarr;
        supportingarr.push_back(1);
        int suffix=1;
        for(int i=nums.size()-1;i>0;i--){
            suffix*=nums[i];
            supportingarr.push_back(suffix);
        }
        int prefix=1;
        int pointer=supportingarr.size()-1;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(supportingarr[pointer]*prefix);
            pointer--;
            prefix*=nums[i];
        }
        return ans;
    }
};