class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        int i=0;
        while(i<s.length()){
            unordered_map<char,int> mpp;
            ans++;
            while(true && i<s.length()){
                if(mpp.find(s[i])!=mpp.end()) break;
                mpp[s[i]]++;
                i++;
            }
        }
        return ans;
    }
};