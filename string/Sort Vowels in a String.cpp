class Solution {
public:
    string sortVowels(string s) {
        string vow;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vow+=s[i];
            }
        }
        sort(vow.begin(),vow.end());
        string t;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                t+=vow[j];
                j++;
            }else{
                t+=s[i];
            }
        }
        return t;
    }
};