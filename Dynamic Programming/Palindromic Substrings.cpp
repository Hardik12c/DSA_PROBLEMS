class Solution {
public:
    bool checkPalindrome(string str,unordered_map<string,bool> &mpp) {
        int s = 0;
        int e = str.length() - 1;
        while (s <= e) {
            if (str[s] != str[e])
                return false;
            s++;
            e--;
        }
        mpp[str]=true;
        return true;
    }
    int recurse(string s, int ind, string temp,unordered_map<string,bool> &mpp) {
        if (ind >= s.length()) {
            return 0;
        }
        temp += s[ind];
        if(mpp.find(temp)!=mpp.end()){
            return 1+recurse(s,ind+1,temp,mpp);
        }
        return (checkPalindrome(temp,mpp) ? 1 : 0) + recurse(s, ind + 1, temp,mpp);
    }
    int countSubstrings(string s) {
        int ans = 0;
        unordered_map<string,bool> mpp;
        for (int i = 0; i < s.length(); i++) {
            ans += recurse(s, i, "",mpp);
        }
        return ans;
    }
};