class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            int add=0,cnt=0;
            for(int j=0;j<nums.size();j++){
                if((add+nums[j])<=queries[i]){
                    add+=nums[j];
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};