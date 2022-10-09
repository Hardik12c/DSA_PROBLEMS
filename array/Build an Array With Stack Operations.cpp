class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int it=0;
        for(int i=1;i<=n;i++){
            int k=it;
            if(st.size()!=target.size()){
                st.push(i);
                ans.push_back("Push");
                it++;
            }
            if(st.top()!=target[k]){
                st.pop();
                ans.push_back("Pop");
                it--;
            }
            if(st.size()==target.size()){
                break;
            }
        }
        return ans;
    }
};