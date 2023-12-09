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

// more optimized Solution
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<groupSizes.size();i++){
            if(mpp.find(groupSizes[i])==mpp.end()){
                vector<int> newVector;
                mpp[groupSizes[i]]=newVector;
            }else{
                vector<int> temp=mpp[groupSizes[i]];
                if(temp.size()==groupSizes[i]){
                    ans.push_back(temp);
                    vector<int> newVector;
                    mpp[groupSizes[i]]=newVector;
                }
            }
            mpp[groupSizes[i]].push_back(i);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};