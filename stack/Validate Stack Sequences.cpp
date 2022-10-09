class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        int i=0;
        while(i<pushed.size()){
            if(!st.empty()&&st.top()==popped[j]){
                st.pop();
                j++;
            }else{
                st.push(pushed[i]);
                i++;
            } 
        }
        while(j<popped.size()){
            if(st.top()!=popped[j]){
                return false;
            }
            st.pop();
            j++;
        }
        return true;
    }
};