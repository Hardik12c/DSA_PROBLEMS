class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans=0;
        string check="";
        for(int i=0;i<s.length();i++){
            check+=s[i];
            if(stoll(check)>k){
                ans++;
                check="";
                check+=s[i];
                if(stoll(check)>k) return -1;
            }  
        }
        if(stoll(check)<=k) ans++;
        return ans;
    }
};