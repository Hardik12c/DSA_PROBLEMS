class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26,0);
        vector<int> check(26,0);
        vector<int> ans;
        if(p.length()>s.length()) return ans;
        int ind=0;
        for(int i=0;i<p.length();i++){
            arr[(p[i]-'a')]++;
        }
        for(int i=0;i<p.length();i++){
            check[(s[i]-'a')]++;
        }
        if(check==arr) ans.push_back(ind);
        for(int i=p.length();i<s.length();i++){
            check[(s[ind]-'a')]--;
            check[(s[i]-'a')]++;
            ind++;
            if(check==arr) ans.push_back(ind);
        }
        return ans;
    }
};