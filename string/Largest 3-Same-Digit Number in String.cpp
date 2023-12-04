class Solution {
public:
    string largestGoodInteger(string num) {
        int count=1;
        string ans="";
        string number="";
        number+=num[0];
        for(int i=1;i<num.length();i++){
            if(num[i]==num[i-1]){
                number+=num[i];
                count++;
            }
            if(count==3){
                ans=max(ans,number);
            }
            if(num[i]!=num[i-1]){
                count=1;
                number="";
                number+=num[i];
            }

        }
        return ans;
    }
};