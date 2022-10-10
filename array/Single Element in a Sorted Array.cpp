class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(mid-1>0 && mid+1>0 &&nums[mid-1]!=nums[mid] &&nums[mid+1]!=nums[mid]) break;
            if(mid-1>=0 && nums[mid-1]==nums[mid]){
                if((mid-s-1)&1) e=mid-2;
                else s=mid+1; 
            }else if(mid+1<=e&& nums[mid+1]==nums[mid]){
                if((e-mid-1)&1) s=mid+2;
                else e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return nums[mid];
    }
};