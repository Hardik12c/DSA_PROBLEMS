class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> s1;
        stack<int> s2;
        for(int i=nums.size()-1;i>=0;i--){
            s2.push(nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!s1.empty()&& s1.top()<=nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                while(!s2.empty() && s2.top()<=nums[i]){
                    s2.pop();
                }
                if(s2.empty()){
                    ans.push_back(-1);
                }else{
                    ans.push_back(s2.top());
                } 
            }else{
                if(s1.empty()){
                    ans.push_back(-1);
                }else{
                    ans.push_back(s1.top());
                } 
            }
            s1.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};