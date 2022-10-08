class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mpp;
        vector<int> push;
        vector<vector<int>> ans;
        for(int i=0;i<groupSizes.size();i++){
            mpp[groupSizes[i]].push_back(i);
        }
        for(auto i:mpp){
            for(int j=0;j<i.second.size();j++){
                if(push.size()==i.first){
                    ans.push_back(push);
                    push.clear();
                } 
                push.push_back(i.second[j]);
            }
            ans.push_back(push);
            push.clear();
        }
        return ans;
    }
};