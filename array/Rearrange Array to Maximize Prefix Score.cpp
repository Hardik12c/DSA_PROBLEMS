class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int score=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>0) score++;
            else break;
        }
        return score;
    }
};