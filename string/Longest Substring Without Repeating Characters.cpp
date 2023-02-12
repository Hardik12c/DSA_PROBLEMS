class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_map<char,int> mpp;
        int ans=1;
        int cnt=0;
        int i=0;
        while(i<s.length()){
            if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]!=i){
                int ind=mpp[s[i]];
                mpp.clear();
                ans=max(cnt,ans);
                mpp[s[i]]=i;
                i=ind+1;
                cnt=0;
            }else{
                mpp[s[i]]=i;
                cnt++;
                i++;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};