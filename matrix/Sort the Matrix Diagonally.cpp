class Solution {
public:
    void arrangeNewMat(vector<vector<int>> &ans, int i,int j,int n,int m,vector<vector<int>> mat){
            int k=i;
            int l=j;
            vector<int> temp;
            while(k<n && l<m){
                temp.push_back(mat[k][l]);
                k++;l++;
            }
            sort(temp.begin(),temp.end());
            k=i;
            l=j;
            int p=0; 
            while(k<n && l<m && p<temp.size()){
                ans[k][l]=temp[p];
                k++;l++;p++;
            }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        int n=mat.size();
        int m=mat[0].size();
        for(int i=n-1;i>=0;i--){
            arrangeNewMat(ans,i,0,n,m,mat);
        }
        for(int i=1;i<m;i++){
            arrangeNewMat(ans,0,i,n,m,mat);
        }
        return ans;
    }
};