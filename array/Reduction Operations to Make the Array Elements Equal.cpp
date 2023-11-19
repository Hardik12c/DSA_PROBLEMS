class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        unordered_map<int,int> mpp;
        
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int k=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]!=-1){
                ans+=(mpp.size()-k)*mpp[nums[i]];
                k++;
                mpp[nums[i]]=-1;
            }
        }
        return ans;
    }
};