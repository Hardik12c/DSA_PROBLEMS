class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> temp;
        vector<int> colorremove;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                colorremove.push_back(neededTime[i-1]);
            }else{
                if(colorremove.size()>0){
                    colorremove.push_back(neededTime[i-1]);
                    temp.push_back(colorremove);
                    vector<int> newsample;
                    colorremove=newsample;
                }
            }
        }
        if(colorremove.size()>0){
            colorremove.push_back(neededTime[neededTime.size()-1]);
            temp.push_back(colorremove);
        }
        int ans=0;
        for(int i=0;i<temp.size();i++){
            sort(temp[i].begin(),temp[i].end());
            for(int j=0;j<temp[i].size()-1;j++){
                ans+=temp[i][j];
            }
        }
        return ans;
    }
};