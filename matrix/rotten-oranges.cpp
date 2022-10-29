class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>qu;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    qu.push({i,j});    
                }
            }
        }
        
        int ans=0;
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){              
                auto element=qu.front();
                qu.pop();
                int row=element.first;
                int column=element.second;
                if(row-1>=0 && grid[row-1][column]==1){
                    grid[row-1][column]=2;
                    qu.push({row-1,column});
                }
                
                if(column-1>=0 && grid[row][column-1]==1){
                    grid[row][column-1]=2;
                    qu.push({row,column-1});
                }
                
                if(row+1<n && grid[row+1][column]==1){
                    grid[row+1][column]=2; 
                    qu.push({row+1,column});
                }
                
                if(column+1<m && grid[row][column+1]==1){
                    grid[row][column+1]=2;
                    qu.push({row,column+1});
                } 
            }
            if(!qu.empty()) ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1; 
            }
        }
        return ans;
    }
};