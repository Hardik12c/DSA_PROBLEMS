class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;
        for (int i = 0; i < paths.size(); i++) {
            string temp = "";
            string begin = "";
            string more = "";
            for (int j = 0; j < paths[i].length(); j++) {
                if (paths[i][j] == '(') {
                    temp = "";
                    while (paths[i][j] != ')') {
                        temp += paths[i][j];
                        j++;
                    }
                    temp += paths[i][j];
                    j++;
                    mpp[temp].push_back(more + '/' + begin);
                }
                if (paths[i][j] != ' ') {
                    begin += paths[i][j];
                } else {
                    if (more == "")
                        more = begin;
                    begin = "";
                }
            }
        }
        for (auto it : mpp) {
            if (it.second.size() > 1) {
                vector<string> temp;
                for (int i = 0; i < it.second.size(); i++) {
                    temp.push_back(it.second[i]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};