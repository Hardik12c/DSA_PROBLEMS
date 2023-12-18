class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int x=INT_MIN;
        int y=INT_MIN;
        int w=INT_MAX; int z=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>x){
                if(nums[i]>y){
                    x=y;
                    y=nums[i];
                }else x=nums[i];
            }
            if(nums[i]<w){
                if(nums[i]<z){
                    w=z;
                    z=nums[i];
                }else w=nums[i];
            }
        }
        return (x*y)-(w*z);
    }
};