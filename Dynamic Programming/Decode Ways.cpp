class Solution {
public:
    int recurse(int ind,string s,vector<int> &dp){
        if(ind>s.length()-1){
            if(s[ind]=='0') return 0;
            return 1;
        } 
        if(dp[ind]!=-1) return dp[ind];
        int sizeOne=0;
        if(s[ind]!='0'){
            sizeOne=recurse(ind+1,s,dp);
        }
        int sizeTwo=0;
        if(ind+1<s.length()){
            int num=s[ind]-'0';
            if(num!=0){
                num=(num*10)+(s[ind+1]-'0');
                if(num<=26){
                    sizeTwo=recurse(ind+2,s,dp);
                }
            }
        }
        return dp[ind]=sizeOne+sizeTwo;
    }
    int numDecodings(string s) {
        if(s.length()==1 && s[0]=='0') return 0;
        vector<int> dp(s.length()+1,-1);
        return recurse(0,s,dp);
    }
};