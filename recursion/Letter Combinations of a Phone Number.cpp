class Solution {
public:
    void recurse(vector<string> keypad,int ind,string digits,string temp,vector<string> &ans){
        if(ind>=digits.size()){
            ans.push_back(temp);
            return;
        }
        string s=keypad[(digits[ind]-'0')-2];
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            recurse(keypad,ind+1,digits,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> keypad={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits=="") return ans;
        recurse(keypad,0,digits,"",ans);
        return ans;
    }
};