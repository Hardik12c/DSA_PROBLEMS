class Solution {
public:
    int myAtoi(string s) {
        string news;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                s=s.substr(i,s.length()-i);
                break;
            }
        }
        long long int n=0;
        string sign="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                if(sign.size()>1 && n==0){
                    return 0;
                } 
                int k=s[i]-'0';
                n=(n*10)+k;
            }else if(s[i]=='-' || s[i]=='+'){
                if(n>0) break;
                if(i>0 && sign=="" ) return 0;
                sign+=s[i];
            }else break;
            if(n>2147483647){
                if(sign=="-"){
                    return -2147483648;
                }
                return 2147483647;
            }
        }
        if(sign[0]=='-'){
            n=n*-1;
        }
        return n;
    }
};