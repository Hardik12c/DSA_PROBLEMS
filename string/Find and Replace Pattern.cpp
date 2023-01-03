class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            unordered_map<char,char> mpp1;
            unordered_map<char,char> mpp2;
            bool flag=true;
            for(int j=0;j<words[i].length();j++){
                if(mpp1.find(pattern[j])==mpp1.end() && mpp2.find(words[i][j])==mpp2.end()){
                    mpp1[pattern[j]]=words[i][j];
                    mpp2[words[i][j]]=pattern[j];
                }else{
                    if(mpp1[pattern[j]]!=words[i][j] || mpp2[words[i][j]]!=pattern[j]){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) ans.push_back(words[i]);
        }
        return ans;
    }
};