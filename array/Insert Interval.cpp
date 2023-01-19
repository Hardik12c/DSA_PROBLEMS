class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n1=-1;int n2=-1;
        int news=newInterval[0];
        int newe=newInterval[1];
        vector<vector<int>> ans;
        bool flag=false;
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(news<start && newe>end){
                if(n1==-1){
                    n1=news;
                }
                n2=newe;
                flag=true;
            }else if(news>=start && news<=end && newe>=start && newe<=end){
                if(n1==-1){
                    n1=start;
                }
                flag=true;
                n2=end;
            }else if(news>=start && news<=end && newe>end){
                if(n1==-1){
                    n1=start;
                }
                flag=true;
                n2=newe;
            }else if(news<start && newe<=end && newe>=start){
                if(n1==-1){
                    n1=news;
                }
                flag=true;
                n2=end;
            }else{
                if(n1!=-1 && n2!=-1){
                    vector<int> temp;
                    temp.push_back(n1);
                    temp.push_back(n2);
                    ans.push_back(temp);
                    n1=-1;n2=-1;
                }
                ans.push_back(intervals[i]);
            }
        }
        if(!flag){
        cout<<"He."<<endl;
            bool t=false;
            for(int i=0;i<ans.size();i++){
                if(ans[i][0]>news){
                    ans.insert(ans.begin()+i,newInterval);
                    t=true;
                    break;
                }
            }
            if(!t){
                ans.push_back(newInterval);
            }
        }
        if(n1!=-1 && n2!=-1){
            vector<int> temp;
            temp.push_back(n1);
            temp.push_back(n2);
            ans.push_back(temp);
        }
        return ans;
    }
};