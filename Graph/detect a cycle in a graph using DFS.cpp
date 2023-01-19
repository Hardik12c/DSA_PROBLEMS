class Solution {
  public:
    bool detectcycle(int src,int parent,vector<int> adj[],vector<int> &vis){
        vis[src]=1;
        for(auto node:adj[src]){
            if(!vis[node]){
                if(detectcycle(node,src,adj,vis)==true){
                    return true;
                }
            }else if(node!=parent){
                return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectcycle(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};