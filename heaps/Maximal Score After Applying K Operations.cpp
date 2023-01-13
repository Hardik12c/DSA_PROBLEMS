class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long score=0;
        while(k>0){
            int num=pq.top();
            pq.pop();
            score+=num;
            num=ceil(num/3.0);
            pq.push(num);
            k--;
        }
        return score;
    }
};