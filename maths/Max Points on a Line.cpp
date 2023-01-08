class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        int mx=INT_MIN;
        for(int i=0;i<points.size();i++){
            unordered_map<float,int> mpp;
            for(int j=i+1;j<points.size();j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                float m=INT_MIN;
                if((x2-x1)!=0) m=float(y2-y1)/float(x2-x1);
                mpp[m]++;
            }
            for(auto i:mpp){
                mx=max(mx,i.second);
            }
        }
        return mx+1;
    }
};