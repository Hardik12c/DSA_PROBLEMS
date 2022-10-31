class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int j=0;j<m;j++){
            int k=j;
            int num=matrix[0][j];
            for(int i=0;i<n;i++){
                if(matrix[i][j]!=num){
                    return false;
                }  
                j++;
                if(j>=m) break;
            }
            j=k;
        }
        
        for(int i=0;i<n;i++){
            int k=i;
            int num=matrix[i][0];
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=num){
                    return false;
                }  
                i++;
                if(i>=n) break;
            }
            i=k;
        }
        return true;
    }
};