class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty()&&st.top().first==s[i]){
                if(st.top().second==k-1){
                    for(int i=0;i<k-1;i++) st.pop();
                }else st.push({s[i],st.top().second+1});
            }else st.push({s[i],1});
        }
        cout<<st.size()<<endl;
        string ans;
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};