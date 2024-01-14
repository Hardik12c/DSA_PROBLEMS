class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int count1=0;
        int count2=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]>=s2[i]) count1++;
            if(s2[i]>=s1[i]) count2++;
        }        
        return count1==s1.length() || count2==s1.length();
    }
};