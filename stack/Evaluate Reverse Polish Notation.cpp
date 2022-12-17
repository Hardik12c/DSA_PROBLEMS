class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="*" &&tokens[i]!="+" && tokens[i]!="/" && tokens[i]!="-"){
                s.push(stoi(tokens[i]));
            }else{
                long long int k=s.top();
                s.pop();
                long long int l=s.top();
                s.pop();
                long long int topush;
                if(tokens[i]=="*") topush=k*l;
                else if(tokens[i]=="-") topush=l-k;
                else if(tokens[i]=="+") topush=k+l;
                else topush=l/k;
                s.push(topush);
            }
        }
        return s.top();
        return 0;
    }
};