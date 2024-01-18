class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n,vector<int>(n,0));
        int row_start=0;int row_end=n-1;
        int col_start=0;int col_end=n-1;
        int num=1;
        while(row_start<=row_end && col_start<=col_end){
            for(int i=col_start;i<=col_end;i++){
                vec[row_start][i]=num;
                num++;
            }
            row_start++;
            for(int i=row_start;i<=row_end;i++){
                vec[i][col_end]=num;
                num++;
            }
            col_end--;
            for(int i=col_end;i>=col_start;i--){
                vec[row_end][i]=num;
                num++;
            }
            row_end--;
            for(int i=row_end;i>=row_start;i--){
                vec[i][col_start]=num;
                num++;
            }
            col_start++;
        }
        return vec;
    }
};