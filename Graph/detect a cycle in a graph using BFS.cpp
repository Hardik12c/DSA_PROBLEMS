class Solution {
  public:
    bool detectcycle(int src,vector<int> adj[],vector<int> &vis){
        vis[src]=1;
        queue<pair<int,int>> qu;
        qu.push({src,-1});
        
        while(!qu.empty()){
            int first=qu.front().first;
            int second=qu.front().second;
            qu.pop();
            for(auto node:adj[first]){
                if(!vis[node]){
                    vis[node]=1;
                    qu.push({node,first});
                }else if(node!=second){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectcycle(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};