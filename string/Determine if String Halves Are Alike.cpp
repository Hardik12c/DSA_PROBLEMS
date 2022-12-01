class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length()/2;
        int c1=0,c2=0;
        for(int i=0;i<s.length();i++){
            char a=s[i];
            if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='O' || a=='I' || a=='U'){
                if(i<n) c1++;
                else c2++;
            }
        }
        return c1==c2;
    }
};