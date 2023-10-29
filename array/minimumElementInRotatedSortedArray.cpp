class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int ans=0;
        int mid=s+(e-s)/2;
        while(s<e){
            if(mid+1<nums.size() &&nums[mid+1]<nums[mid]){
                return nums[mid+1];
            }else if(mid-1>=0 && nums[mid-1]>nums[mid]){
                return nums[mid];
            }else if(nums[mid]<nums[s]){
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return nums[ans];
    }
};