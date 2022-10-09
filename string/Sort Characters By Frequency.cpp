class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        map<int,vector<char>,greater<int>> mp;
        for(auto i:mpp){
            mp[i.second].push_back(i.first);
        }   
        string l;
        for(auto i:mp){
            for(int j=0;j<i.second.size();j++){
                int count=0;
                while(count<i.first){
                    l.push_back(i.second[j]);
                    count++;
                }
            }
        }
        return l;
    }
};
// time complexity will be nlogn as there are three loops but in every case they will generate a time of o(n) and o(nlogn) time to sort for a map