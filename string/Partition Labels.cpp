class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++) mpp[s[i]]=i;
        vector<int> ans;
        int i=0;
        while(i<s.length()){
            int j=mpp[s[i]];
            for(int k=i;k<j;k++){
                if(mpp[s[k]]>j) j=mpp[s[k]];
            }
            j++;
            ans.push_back(j-i);
            i=j;
        }
        return ans;
    }
};