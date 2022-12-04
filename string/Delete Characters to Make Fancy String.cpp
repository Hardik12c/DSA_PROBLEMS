class Solution {
public:
    string makeFancyString(string s) {
        int a=1;
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) a++;
            else a=1;
            ans+=s[i];
            if(a==3){
                ans.pop_back();
                a--;
            } 
        }
        return ans;
    }
};