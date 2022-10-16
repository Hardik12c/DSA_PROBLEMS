class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1 || nums[0]==nums.size()-1) return true;
        if(nums[0]==0) return false;
        int index;
        int n=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=(n-i)) n=i;
        }
        if(n==0) return true;
        return false;
    }
};