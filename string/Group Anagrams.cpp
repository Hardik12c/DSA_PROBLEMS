class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,int> mpp;
        int count=0;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            vector<int> arr(26,0);
            for(int j=0;j<strs[i].length();j++){
                arr[strs[i][j]-'a']++;
            }
            if(mpp.find(arr)==mpp.end()){
                ans.push_back({strs[i]});
                mpp[arr]=count;
                count++;
            }else{
                ans[mpp[arr]].push_back(strs[i]);
            }
        }
        return ans;
    }
};