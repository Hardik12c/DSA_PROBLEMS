class Solution {
public:
    int getSumAfterDivisor(vector<int> nums,int divis){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i]/divis+(nums[i]%divis>0?1:0);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            int sum=getSumAfterDivisor(nums,mid);
            cout<<mid<<" "<<sum<<endl;
            if(sum<=threshold){
                ans=min(ans,mid);
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};