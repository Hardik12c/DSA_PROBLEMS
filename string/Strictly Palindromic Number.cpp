class Solution {
public:
    bool checkPalindrome(string s){
        int i=0;
        int e=s.length()-1;
        while(i<=e){
            if(s[i]!=s[e]){
                return false;
            }
            i++;e--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        int e=n-2;
        for(int i=2;i<=e;i++){
           string s="";
            int k=n;
           while(n!=0){
               if(n%i==0){
                   s+='0';
               }else{
                   s+=(n%i)+'0';
               }
               n/=i;
           }
           n=k;
           cout<<s<<endl;
           if(!checkPalindrome(s)){
               return false;
           }
        }
        return true;
    }
};