class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> mpp;
        int mx = INT_MIN;
        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]]++;
            mx = max(mpp[s[i]], mx);
        }
        string ans = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (mpp[s[i]] == mx) {
                ans += s[i];
                mpp[s[i]]=0;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};