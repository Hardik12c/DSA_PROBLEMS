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
    int totalNQueens(int n) {
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
        return ans.size();
    }
};

//optimized and good solution
class Solution {
public:
    int recurse(int ind ,int n,vector<int> row,vector<int> upper,vector<int> down){
        if(ind>=n){
            return 1;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!row[i] && !upper[n+ind-i-1] && !down[ind+i]){
                row[i]=1;
                upper[n+ind-i-1]=1;
                down[ind+i]=1;
                count+=recurse(ind+1,n,row,upper,down);
                row[i]=0;
                upper[n+ind-i-1]=0;
                down[ind+i]=0;
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<int> row(n,0);
        vector<int> upper(2*n,0);
        vector<int> down(2*n,0);
        return recurse(0,n,row,upper,down);
    }
};