class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<vector<int>> ans;
        int mxnum=INT_MIN;
        int value=0;
        for(auto it:mpp){
            if(it.second>mxnum){
                mxnum=it.second;
                value=it.first;
            }
        }
        while(mxnum!=0){
            vector<int> temp;
            temp.push_back(value);
            ans.push_back(temp);
            mxnum--;
        }
        for(auto it:mpp){
            int num=it.second;
            if(it.first!=value && num>0){
                int i=0;
                while(num!=0){
                    ans[i].push_back(it.first);
                    num--;
                    i++;
                }
            }
            mpp[it.first]=0;
        }
        return ans;
    }
};