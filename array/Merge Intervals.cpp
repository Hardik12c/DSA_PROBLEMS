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
//another solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            int num1=intervals[i][0];
            int num2=intervals[i][1];
            if(temp[1]<=num2 && temp[1]>=num1){
                temp[1]=num2;
            }else if(num2<temp[1]){
                continue;
            }else{
                ans.push_back(temp);
                temp=intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};