class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> st;
        recursive(n,k,ans,st,1);
        return ans;
    }
    void recursive(int n,int k,vector<vector<int>> &ans, vector<int> st,int i){
        if(st.size()==k){
            ans.push_back(st);
            return;
        }
        for(int j=i;j<=n;j++){
            st.push_back(j);
            recursive(n,k,ans,st,j+1);
            st.pop_back();
        }
    }
};