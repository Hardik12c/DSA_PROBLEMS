class Solution {
public:
    static bool compare(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int,int>> v;

        for(int i=0;i<score.size();i++){
            v.push_back({i,score[i][k]});
        }
        sort(v.begin(),v.end(),compare);

        vector<vector<int>> ans;

        for(int i=0;i<score.size();i++){
            ans.push_back(score[v[i].first]);
        }
        return ans;

    }
};