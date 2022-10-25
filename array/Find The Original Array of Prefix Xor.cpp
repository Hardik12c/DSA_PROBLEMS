class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int c=0;
        for(int i=0;i<pref.size();i++){
            ans.push_back(c^pref[i]);
            c=c^ans[i];
        }
        return ans;
    }
};