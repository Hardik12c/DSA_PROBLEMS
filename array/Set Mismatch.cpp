class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1) ans.push_back(nums[i]);
        }
        for(int i=1;i<=nums.size();i++){
            if(mpp[i]==0){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};

//without extra space
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0){
                ans.push_back(abs(nums[i]));
            }else nums[abs(nums[i])-1]*=-1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};