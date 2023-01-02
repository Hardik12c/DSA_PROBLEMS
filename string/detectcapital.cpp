class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag=true;
        if(word[0]>='a' && word[0]<='z') flag=false;
        if(flag){
            for(int i=1;i<word.length();i++){
                if(word[i]<'A' || word[i]>'Z'){
                    flag=false;
                    break;
                }else flag=true;
            }
        }
        if(flag) return true;
        flag=true;
        for(int i=1;i<word.length();i++){
            if(word[i]<'a' || word[i]>'z'){
                flag=false;
                break;
            }else flag=true;
        }
        return flag;
    }
};