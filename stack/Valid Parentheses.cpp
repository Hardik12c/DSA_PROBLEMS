class Solution {
public:
    bool isValid(string s) {
        stack<char> store;
        for(int i=0;i<s.length();i++){
            if(!store.empty() &&( (s[i]==')' && store.top()=='(')||(s[i]=='}' && store.top()=='{')||(s[i]==']' && store.top()=='['))){
                store.pop();
            }else store.push(s[i]);
        }
        return store.empty();
    }
};