class Solution {
public:
    bool isPalindrome(string s) {
        string news="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                news+=tolower(s[i]);
            }
        }
        int i=0;
        int j=news.length()-1;
        while(i<=j){
            if(news[i]!=news[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
};