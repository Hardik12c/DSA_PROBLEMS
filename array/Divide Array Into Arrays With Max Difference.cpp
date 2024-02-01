class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i+=3){
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            if(c-a<=k && c-b<=k && b-a<=k){
                vector<int> temp;
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                ans.push_back(temp);
            }else{
                vector<vector<int>> newAns;
                return newAns;
            }
        }
        return ans;
    }
};