class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int ans=-1;
        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            if(leftSum==sum){
                ans=i;
                break;
            }
            leftSum+=nums[i];
        }
        return ans;    
    }
};