class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mpp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                mpp[words[i][j]]++;
            }
        }
        int count=mpp[words[0][0]];
        for(auto it:mpp){
            if(it.second!=count) return false;
        }
        return true;
    }
};