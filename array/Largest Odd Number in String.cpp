class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        string temp="";
        for(int i=0;i<num.size();i++){
            if((num[i]-'0')&1){
                temp+=num[i];
                ans+=temp;
                temp="";
            }else{
              temp+=num[i];
            }
        }
        return ans;
    }
};