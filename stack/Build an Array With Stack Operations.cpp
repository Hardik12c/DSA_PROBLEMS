class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int num=0;
        stack<int> s;
        int i=1;
        vector<string> ans;
        while(i<=n && num<target.size()){
            s.push(i);
            ans.push_back("Push");
            cout<<"hello"<<i<<endl;
            while(s.top()!=target[num]){
                s.pop();
                ans.push_back("Pop");
                i++;
                s.push(i);
                ans.push_back("Push");
            }
            i++;
            num++;
        
        }
        return ans;
    }
};