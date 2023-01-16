class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int initial=image[sr][sc];
        if(color==initial) return image;
        queue<pair<int,int>> qu;
        image[sr][sc]=color;
        qu.push({sr,sc});
        while(!qu.empty()){
            int row=qu.front().first;
            int col=qu.front().second;
            cout<<image[row][col]<<endl;
            qu.pop();
            if(row+1<n &&image[row+1][col]==initial){
                image[row+1][col]=color;
                qu.push({row+1,col});
            }
            if(row-1>=0 && image[row-1][col]==initial){
                image[row-1][col]=color;
                qu.push({row-1,col});
            }
            if(col-1>=0 && image[row][col-1]==initial){
                qu.push({row,col-1});
                image[row][col-1]=color;
            }
            if(col+1 <m && image[row][col+1]==initial){
                qu.push({row,col+1});
                image[row][col+1]=color;
            }
        }
        return image;
    }
};