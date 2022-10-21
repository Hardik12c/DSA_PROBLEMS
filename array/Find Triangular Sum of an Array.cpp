class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        while(n>1){
            for(int i=0;i<n;i++){
                if(i+1<n){
                    nums[i]=(nums[i]+nums[i+1])%10;
                }
            }
            n--;
        }
        return nums[0];
    }
};