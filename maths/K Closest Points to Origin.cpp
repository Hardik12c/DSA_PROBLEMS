class Solution {
public:
    float euclidean(int x1,int y1){
        return (pow(pow(x1,2)+pow(y1,2),0.5));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        map<float,vector<int>> mpp;
        for(int i=0;i<points.size();i++){
            float k=euclidean(points[i][0],points[i][1]);
            mpp[k].push_back(i);
        }
        for(auto i:mpp){
            for(int j=0;j<i.second.size();j++){
                ans.push_back(points[i.second[j]]);
                k--;
                if(k<=0) break;
            }
            if(k<=0) break;
        }
        return ans;
    }
};