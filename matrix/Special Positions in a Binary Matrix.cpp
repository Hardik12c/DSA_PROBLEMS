class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    bool flag=true;
                    for(int k=0;k<m;k++){
                        if(mat[i][k]==1 && k!=j){
                            flag=false;
                            break;
                        }
                    }
                    for(int k=0;k<n;k++){
                        if(mat[k][j]==1 && k!=i){
                            flag=false;
                            break;
                        }
                    }
                    if(flag) count++;
                    break;
                }
            }
        }
        return count;
    }
};