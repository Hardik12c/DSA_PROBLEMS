class Solution {
public:
    int reverseinteger(int num){
        int newnum=0;
        while(num!=0){
            int n=num%10;
            num/=10;
            newnum=(newnum*10)+n;
        }
        return newnum;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            int num=reverseinteger(nums[i]);            
            mpp[num]++;
        }
        for(auto it:mpp){
            ans++;
        } 
        return ans;
    }
};