class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> mpp;
        vector<int> ans(k,0);
        for(int i=0;i<logs.size();i++){
            mpp[logs[i][0]].insert(logs[i][1]);
        }
        for(auto it:mpp){
            ans[it.second.size()-1]++;
        }
        return ans;
    }
};