    bool compare(string &a,string &b){
        return a.length()<b.length();
    }
class Solution {
public:
    bool check(string &a,string &b){
        if(a.size()-1!=b.size()) return false;
        int i=0,j=0;
        while(i<a.length()){
            if(a[i]==b[j]){
                i++;j++;
            }else{
                i++;
            }
        }
        if(i==a.length() && j==b.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> dp(n,1);
        int len=1;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
                len=max(len,dp[i]);
            }
        }
        return len;
    }
};