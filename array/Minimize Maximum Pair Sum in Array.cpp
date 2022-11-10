class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;
        int sum=INT_MIN;
        while(s<e){
            sum=max(sum,nums[s]+nums[e]);
            s++;e--;
        }
        return sum;
    }
};