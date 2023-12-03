class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int m=s.length();
        int x=startPos[0];
        int y=startPos[1];
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=i;j<m;j++){
                if(s[j]=='L'){
                    if(y-1<0) break;
                    y-=1;
                }else if(s[j]=='U'){
                    if(x-1<0) break;
                    x-=1;
                }else if(s[j]=='D'){
                    if(x+1>=n) break;
                    x+=1;
                }else{
                    if(y+1>=n) break;
                    y+=1;
                }
                count++;
            }
            ans.push_back(count);
            x=startPos[0];
            y=startPos[1];
        }
        return ans;
    }
};