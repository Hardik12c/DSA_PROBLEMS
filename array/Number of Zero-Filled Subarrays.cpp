class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long num=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) num++;
            else{
                ans+=num+((num*(num-1))/2); 
                num=0;
            }
        }
        ans+=num+((num*(num-1))/2); 

        return ans;
    }
};