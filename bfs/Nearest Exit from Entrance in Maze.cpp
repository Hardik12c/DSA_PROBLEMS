class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        int ans=INT_MAX;
        queue<pair<int,int>> qu;
        int dis=0;
        qu.push({entrance[0],entrance[1]});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[entrance[0]][entrance[1]] = 1;
        while(!qu.empty()){
            int k=qu.size();

            for(int i=0;i<k;i++){
                auto temp=qu.front();
                qu.pop();
                int x=temp.first;
                int y=temp.second;
                if((x==0 || x==n-1 ||y==m-1 || y==0)){
                    if(x!=entrance[0]||y!=entrance[1]){
                        return dis;
                    }
                }
                if((x-1)>=0 && !vis[x-1][y]&&maze[x-1][y]!='+'){
                    vis[x-1][y]=1;
                    qu.push({x-1,y});
                }
                if((x+1)<=n-1&&!vis[x+1][y] && maze[x+1][y]!='+'){
                    vis[x+1][y]=1;
                    qu.push({x+1,y});
                }
                if(y-1>=0 && !vis[x][y-1]&&maze[x][y-1]!='+'){
                    vis[x][y-1]=1;
                    qu.push({x,y-1});
                }
                if(y+1<m &&!vis[x][y+1]&& maze[x][y+1]!='+'){
                    vis[x][y+1]=1;
                    qu.push({x,y+1});
                }
            }
            dis++;
        }
        return -1;
    }
};