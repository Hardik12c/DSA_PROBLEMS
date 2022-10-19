class Solution {
public:
    static bool func(pair<string,int> a,pair<string,int> b){
        // if frequency of two words are equal then sorting them lexicographically
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        // frequency sorting
        map<string,int> mpp;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }
        vector<pair<string,int>> v;
        for(auto i:mpp){
            v.push_back({i.first,i.second});
        }
        // using a function to sort
        sort(v.begin(),v.end(),func);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};