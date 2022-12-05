class Solution {
public:
    string thousandSeparator(int n) {
        string s="";
        if(n==0) return "0";
        int count=0;
        while(n!=0){
            int k=n%10;
            s+=k+'0';
            count++;
            if(count==3){
                count=0;                
                s+='.';
            }
            n=n/10;
        }
        if(s[s.length()-1]=='.') s.pop_back();
        reverse(s.begin(),s.end());
        return s;
    }
};