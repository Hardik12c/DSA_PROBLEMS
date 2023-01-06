class Solution{
    public:
    int LongestBitonicSequence(vector<int>nums)
    {
        vector<int> dp1(nums.size(),1);
        vector<int> dp2(nums.size(),1);
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
            for(int j=n-1;j>n-1-i;j--){
                if(nums[n-1-i]>nums[j]){
                    dp2[n-1-i]=max(dp2[n-1-i],1+dp2[j]);
                }
            }
        }
        int maxi=1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }
};