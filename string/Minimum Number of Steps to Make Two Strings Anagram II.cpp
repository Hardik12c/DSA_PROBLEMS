class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpp[t[i]]--;
        }
        int ans=0;
        for(auto it:mpp){
            ans+=abs(it.second);
        }
        return ans;
    }
};