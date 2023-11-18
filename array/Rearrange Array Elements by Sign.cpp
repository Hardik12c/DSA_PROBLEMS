class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int pos=0;
        int neg=0;
        while(pos<nums.size()|| neg<nums.size()){
            while( pos<nums.size() && nums[pos]<0){
                pos++;
            }
            if(pos<nums.size()){
                ans.push_back(nums[pos]);
                pos++;
            }
            while(neg<nums.size() && nums[neg]>0){ 
                neg++;
            }
            if(neg<nums.size()){
                ans.push_back(nums[neg]);
                neg++;
            }
        }
        return ans;
    }
};