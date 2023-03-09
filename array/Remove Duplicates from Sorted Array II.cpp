class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num=nums[0];
        int cnt=1;
        int total=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]==num){
                cnt++;
                if(cnt>2){
                    total--;
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }else{
                cnt=1;
                num=nums[i];
            }
        }
        return total;
    }
};