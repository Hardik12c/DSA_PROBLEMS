class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int lr=i-k;
            int ur=i+k;
            if(lr<0) lr=0;
            if(ur>=n) ur=n-1;
            for(int j=0;j<m;j++){
                int lc=j-k;
                int uc=j+k;
                if(lc<0) lc=0;
                if(uc>=m) uc=m-1;
                int sum=0;
                for(int l=lr;l<=ur;l++){
                    for(int m=lc;m<=uc;m++){
                        sum+=mat[l][m];
                    }
                }
                ans[i][j]=sum;
            }
        }
        return ans;
    }
};