class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> mpp;
        for(int i=0;i<paths.size();i++){
            mpp[paths[i][0]]=paths[i][1];
        }
        string a=paths[0][0];
        while(mpp.find(a)!=mpp.end()){
            a=mpp[a];
        }
        return a;
    }
};