class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()=='[' && s[i]==']'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        int k=st.size()/2;
        return((k/2)+(k%2));
    }
};