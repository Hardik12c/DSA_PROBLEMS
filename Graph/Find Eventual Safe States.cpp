class Solution {
public:
    bool dfs(vector<int> &vis,vector<int>&path,vector<vector<int>> &graph,int node,vector<int> &ans){
        vis[node]=1;
        path[node]=1;
        for(int i=0;i<graph[node].size();i++){
            if(!vis[graph[node][i]]){
                if(dfs(vis,path,graph,graph[node][i],ans)){
                    return true;
                }
            }else if(path[graph[node][i]]){
                return true;
            }
        }
        ans.push_back(node);
        path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> path(graph.size(),0);
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(vis,path,graph,i,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};