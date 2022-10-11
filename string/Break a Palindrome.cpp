class Solution {
public:
    string breakPalindrome(string palindrome) {
       if(palindrome.length()<=1){
           return "";
       } 
       int s=0;int e=palindrome.length()-1;
       while(s<e){
           if(palindrome[s]!='a'&& palindrome[e]!='a'){
               palindrome[s]='a';
               break;
           }else if(s+1>=e-1){
               palindrome[palindrome.length()-1]='b';
               break;
           }else{
               s++;e--;
           }
       }
       return palindrome;
    }
};