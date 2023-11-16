class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k==0) return;
        queue<int> qu;
        for(int i=nums.size()-k;i<nums.size();i++){
            qu.push(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++){
            qu.push(nums[i])+;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=qu.front();
            qu.pop();
        }
    }
};