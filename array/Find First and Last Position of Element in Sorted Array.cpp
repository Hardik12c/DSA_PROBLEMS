class Solution {
public:
    int startingindex(vector<int> nums,int target){
        int s=0;int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int k=-1;
        while(s<=e){
            if(target==nums[mid]){
                k=mid;
                e=mid-1;
            }else if(target<nums[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return k;
    }
    int endingindex(vector<int> nums,int target){
        int s=0;int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int k=-1;
        while(s<=e){
            if(target==nums[mid]){
                k=mid;
                s=mid+1;
            }else if(target<nums[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return k;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(startingindex(nums,target));
        ans.push_back(endingindex(nums,target));
        return ans;
    }
};