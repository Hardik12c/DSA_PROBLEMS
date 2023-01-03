class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        int onec=0,zeroc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) zeroc++;
                else onec++;
            }
            for(int j=0;j<m;j++){
                ans[i][j]=onec-zeroc;
            }
            zeroc=0;
            onec=0;
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]==0) zeroc++;
                else onec++;
            }
            for(int i=0;i<n;i++){
                ans[i][j]+=onec-zeroc;
            }
            zeroc=0;
            onec=0;
        }
        return ans;
    }
};