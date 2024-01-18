class Solution {
public:
    bool check(int rows,int cols,int row,int col){
        if(col>=0 && row>=0 && row<rows && col<cols) return true;
        return false;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        int row = rStart;
        int col = cStart;
        int count = 1;
        vector<vector<int>> ans;
        ans.push_back({row, col});
        while (ans.size() < rows * cols) {
            while (col < cStart + count) {
                col++;
                if (check(rows,cols,row,col)) {
                    ans.push_back({row, col});
                }
            }
            while (row < rStart + count) {
                row++;
                if (check(rows,cols,row,col)) {
                    ans.push_back({row, col});
                }
            }
            while (col > cStart - count) {
                col--;
                if (check(rows,cols,row,col)) {
                    ans.push_back({row, col});
                }
            }
            while (row > rStart - count) {
                row--;
                if (check(rows,cols,row,col)) {
                    ans.push_back({row, col});
                }
            }
            while (col < cStart) {
                col++;
                if (check(rows,cols,row,col)) {
                    ans.push_back({row, col});
                }
            }
            count++;
        }
        return ans;
    }
};