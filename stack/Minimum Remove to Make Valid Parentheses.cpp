class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }
            if(s[i]==')'){
                if(count>0){
                    count--;
                }else{
                    continue;
                }
            }
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            if(count>0 && st.top()=='('){
                count--;
                st.pop();
                continue;
            }
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};