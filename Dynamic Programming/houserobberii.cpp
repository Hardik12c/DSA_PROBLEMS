class Solution {
public:
    int getmaxmoney(vector<int>& ans){
        int prev1=ans[0];int prev2=0;
        for(int i=1;i<ans.size();i++){
            int take=ans[i];
            if(i>1){
                take+=prev2;
            }
            int nottake=prev1;
            int curr=max(take,nottake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> startz,starten;
        for(int i=0;i<nums.size();i++){
            if(i!=0) startz.push_back(nums[i]);
            if(i!=nums.size()-1) starten.push_back(nums[i]);
        }
        return max(getmaxmoney(starten),getmaxmoney(startz));
    }
};