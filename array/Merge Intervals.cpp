class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            int num=intervals[i][1];
            int j=i;
            while(j+1<intervals.size()&&intervals[j+1][0]>=intervals[i][0] && intervals[j+1][0]<=num){
                num=max(num,intervals[j+1][1]);
                j++;
            }
            i=j;
            temp.push_back(num);
            ans.push_back(temp);
        }
        return ans;
    }
};