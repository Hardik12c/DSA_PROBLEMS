#include <bits/stdc++.h>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> wordvec;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                str+=s[i];
            }else{
                wordvec.push_back(str);
                str="";
            }
        }
        wordvec.push_back(str);
        unordered_map<char,string> mpp1;
        unordered_map<string,char> mpp2;
        if(wordvec.size()!=pattern.length()) return false;
        for(int i=0;i<pattern.length();i++){
            if(mpp1.find(pattern[i])==mpp1.end() && mpp2.find(wordvec[i])==mpp2.end()){
                mpp1[pattern[i]]=wordvec[i];
                mpp2[wordvec[i]]=pattern[i];
            }
            else if(mpp1[pattern[i]]!=wordvec[i] || mpp2[wordvec[i]]!=pattern[i]){
                return false;
            }
        }
        return true;
    }
};