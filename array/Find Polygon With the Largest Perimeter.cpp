class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1;
        sort(nums.begin(),nums.end());
        long long perm=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<perm){
                ans=ans>(perm+nums[i])?ans:(perm+nums[i]);
            }
            perm+=nums[i];
        }
        return ans;
    }
};