class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        long k,l;
        while(s<e){
            if(mid-1<0){
                k=LONG_MIN;
            }else{
                k=nums[mid-1];
            }
            if(mid+1>nums.size()-1){
                l=LONG_MIN;
            }else{
                l=nums[mid+1];
            }
            if(nums[mid]>k && nums[mid]>l){
                return mid;
            }else if(nums[mid]>k){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
            
        }
        return mid; 
    }
};