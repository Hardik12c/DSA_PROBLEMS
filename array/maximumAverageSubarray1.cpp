class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int temp=sum;
        for(int i=k;i<nums.size();i++){
           temp-=nums[i-k];
           temp+=nums[i];
           sum=max(sum,temp);
        }
        return sum/double(k);
    }
};