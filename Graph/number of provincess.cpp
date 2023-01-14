class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int i,vector<int> &vis){
        vis[i]=1;

        for(int j=0;j<isConnected[i].size();j++){
            if(i!=j && isConnected[i][j]==1 &&!vis[j]){
                dfs(isConnected,j,vis);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> ans;
        int cnt=0;
        vector<int> isvisited(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            if(!isvisited[i]){
                cnt++;
                dfs(isConnected,i,isvisited);
            }
        }
        return cnt;
    }
};