class Solution {
public:
    int maxPower(string s) {
        int mx=1;
        int num=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                num++;
            }else num=1;

            mx=max(num,mx);
        }
        return mx;
    }
};