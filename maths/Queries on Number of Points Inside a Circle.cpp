class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int x1=queries[i][0];
            int y1=queries[i][1];
            int radius=queries[i][2];
            for(int j=0;j<points.size();j++){
                float dis=pow((pow((x1-points[j][0]),2)+pow((y1-points[j][1]),2)),0.5);
                if(dis<=radius){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};