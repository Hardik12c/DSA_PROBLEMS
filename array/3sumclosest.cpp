class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans;
        int largestdistance=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int s=i+1;
            int e=nums.size()-1;
            int first=nums[i];
            while(s<e){
                int sum=first+nums[s]+nums[e];
                if(abs(sum-target)<=largestdistance){
                    ans=sum;
                    largestdistance=abs(sum-target);
                }
                if(sum>target){
                    e--;
                }else{
                    s++;
                }
            }
        }
        return ans;
    }
};