class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=s.length()-1;i>=0;i--){
            st.push(s[i]);
        }
        string ans="";
        char temp=' ';
        bool flag=false;
        while(!st.empty()){
            char a=st.top();
            st.pop();
            ans+=a;
            if(temp!=' '){
                if((a>='a' &&a<='z')){
                    if(temp==(a-'a'+'A')){
                        ans.pop_back();
                        ans.pop_back();
                        for(int i=ans.length()-1;i>=0;i--) st.push(ans[i]);
                        ans="";
                        flag=true;
                    }
                }else if(a>='A' && a<='Z'){
                    if(temp==a-'A'+'a'){
                        ans.pop_back();
                        ans.pop_back();
                        for(int i=ans.length()-1;i>=0;i--) st.push(ans[i]);
                        ans="";
                        flag=true;
                    }
                }
            }
            if(flag){
                temp=' ';
                flag=false;
            }
                
            else temp=a;
        }
        return ans;
    }
};