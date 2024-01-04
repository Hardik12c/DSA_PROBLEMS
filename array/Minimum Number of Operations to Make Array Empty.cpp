class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int count=0;
        for(auto it:mpp){
            if(it.second==1){
                return -1;
            }
            int num=it.second;
            count+=num/3;
            num=num%3;
            count+=num>0?1:0;
        }
        return count;
    }
};