class Solution {
public:
    int maxScore(string s) {
        int right=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='1') right++;
        }
        int left=0;
        if(s[0]=='0') left++;
        int ans=left+right;
        for(int i=1;i<s.length()-1;i++){
            if(s[i]=='0') left++;
            else right--;
            cout<<left<<" "<<right<<endl;
            ans=max(ans,left+right);
        }
        return ans;
    }
};