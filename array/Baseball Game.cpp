class Solution {
public:
    int calPoints(vector<string>& operation) {
        vector<int> ans;
        for(int i=0;i<operation.size();i++){
            if(operation[i]=="C"){
                ans.pop_back();
            }else if(operation[i]=="D"){
                ans.push_back((ans[ans.size()-1])*2);
            }else if(operation[i]=="+"){
                ans.push_back((ans[ans.size()-1])+(ans[ans.size()-2]));
            }else{
                ans.push_back(stoi(operation[i]));
            }
        }
        int a=0;
        for(int i=0;i<ans.size();i++){
            a+=ans[i];
        }
        return a;
    }
};