class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check for row
        for(int i=0;i<9;i++){
            unordered_map<char,int> mpp;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    mpp[board[i][j]]++;
                }
                if(mpp[board[i][j]]>1){
                    return false;
                }
            }
        }
        // check for column
        for(int j=0;j<9;j++){
            unordered_map<char,int> mpp;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    mpp[board[i][j]]++;
                }
                if(mpp[board[i][j]]>1){
                    return false;
                }
            }
        }
        // check for grid
        for(int i=0;i<3;i++){

            for(int j=0;j<3;j++){
                unordered_map<char,int> mpp;
                for(int row=0;row<3;row++){

                    for(int col=0;col<3;col++){
                        char c=board[row+(i*3)][col+(j*3)];
                        if(c!='.'){
                            mpp[c]++;
                        }
                        if(mpp[c]>1){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};