class Solution {
public:
    void solve(vector<string> &ans,int s,int e,int n,string st){
        if(e>s) return;
        if(s+e==n*2){
            if(s==e){
                ans.push_back(st);
            }
            return;
        }
        st+='(';
        solve(ans,s+1,e,n,st);
        st.pop_back();
        st+=')';
        solve(ans,s,e+1,n,st);
        st.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,0,0,n,"");
        return ans;
    }
};