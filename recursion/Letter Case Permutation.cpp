class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        recurse(0,s,ans);
        return ans;
    }
    void recurse(int i,string s,vector<string> &ans){
        if(i>=s.length()){
            ans.push_back(s);
            return;
        }
        
        recurse(i+1,s,ans);
        
        if(s[i]>='a' && s[i]<='z'){
            s[i]=s[i]-'a'+'A';
            recurse(i+1,s,ans);
        }
        else if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
            recurse(i+1,s,ans);
        }
    }
};