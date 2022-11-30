class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        unordered_map<int,vector<int>> freq;
        for(auto i:mpp){
            freq[i.second].push_back(i.first);
        }
        for(auto i:freq){
            if(i.second.size()>1) return false;
        }
        return true;
    }
};