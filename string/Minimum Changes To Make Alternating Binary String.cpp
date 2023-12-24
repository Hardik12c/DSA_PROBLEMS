class Solution {
public:
    int minOperations(string s) {
        int oneZero=0;
        int zeroOne=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(i&1){
                    zeroOne++;
                }else{
                    oneZero++;
                }
            }else{
                if(i&1){
                    oneZero++;
                }else{
                    zeroOne++;
                }
            }
        }
        return min(zeroOne,oneZero);
    }
};