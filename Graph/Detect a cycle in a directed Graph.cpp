class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<int>&vis,vector<int>&path,int node){
        vis[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,path,it)==true) return true;
            }else if(path[it]) return true;
        }
        
        
        path[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,path,i)){
                    return true;
                }
            }
        }
        return false;
    }
};