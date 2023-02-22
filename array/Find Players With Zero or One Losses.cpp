class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mpp;
        for(int i=0;i<matches.size();i++){
            mpp[matches[i][1]]++;
            if(mpp.find(matches[i][0])==mpp.end()){
                mpp[matches[i][0]]=0;
            }
        }
        vector<int> first;
        vector<int> second;
        vector<vector<int>> ans;
        for(auto it:mpp){
            if(it.second==0){
                first.push_back(it.first);
            }
            if(it.second==1) second.push_back(it.first);
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};