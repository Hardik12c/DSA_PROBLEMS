void solve(int col,vector<vector<string>> &ans,int n,vector<string> temp,vector<int> leftrow,vector<int> downdiagonal,vector<int> updiagonal){
    if(col>=n){
        ans.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && downdiagonal[row+col]==0 &&updiagonal[n-1+(col-row)]==0){
            leftrow[row]=1;
            downdiagonal[row+col]=1;
            updiagonal[n-1+(col-row)]=1;
            temp[row][col]='Q';
            solve(col+1,ans,n,temp,leftrow,downdiagonal,updiagonal);
            temp[row][col]='.';
            leftrow[row]=0;
            downdiagonal[row+col]=0;
            updiagonal[n-1+(col-row)]=0;
        }
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> temp(n);
        for(int i=0;i<n;i++){
            temp[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>updiagonal(2*n-1,0);
        vector<int>downdiagonal(2*n-1,0);
        solve(0,ans,n,temp,leftrow,downdiagonal,updiagonal);
        return ans;
        
    }
};