class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int,greater<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int count=0;
        int ans;
        for(auto it:mpp){
            if(count==0) ans=it.first;
            count++;
            if(count==3){
            ans=it.first;
            break;    
            } 
        }
        return ans;
    }
};