class Solution {
public:
    bool check(string s){
        int l=0;int e=s.length()-1;
        while(l<e){
            if(s[l]!=s[e]){
                return false;
            }
            l++;e--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> temp,string s){
        if(s.length()==0){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<s.length();i++){
            string take=s.substr(0,i+1);
            if(check(take)){
                temp.push_back(take);
                solve(ans,temp,s.substr(i+1));
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans,temp,s);
        return ans;
    }
};