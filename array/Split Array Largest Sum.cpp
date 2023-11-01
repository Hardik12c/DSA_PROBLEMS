class Solution {
public:
    int getSplits(vector<int> nums,int maxSum){
        int splitCount=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>maxSum){
                sum=0;
                splitCount++;
            }
            sum+=nums[i];
        }
        return splitCount;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int s=*max_element(nums.begin(),nums.end());
        int e=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            int splitCount=getSplits(nums,mid);
            if(splitCount>k){
                s=mid+1;
            }else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};