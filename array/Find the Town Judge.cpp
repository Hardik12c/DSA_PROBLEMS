class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1) return 1;
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<trust.size();i++){
            mpp[trust[i][0]].push_back(trust[i][1]);
        }
        unordered_map<int,int> frequency;
        for(auto it:mpp){
            for(int i=0;i<it.second.size();i++){
                frequency[it.second[i]]++;
            }
        }
        for(auto it:frequency){
            if(it.second==n-1 && mpp.find(it.first)==mpp.end()){
                return it.first;
            } 
            cout<<it.first<<" "<<it.second<<endl;
        }
        return -1;
    }
};