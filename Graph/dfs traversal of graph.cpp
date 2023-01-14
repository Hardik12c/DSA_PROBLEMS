class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> &ans,vector<int> adj[],vector<int> &isvisited,int node){
        isvisited[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!isvisited[it]){
                dfs(ans,adj,isvisited,it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> isvisited(V,0);
        vector<int> ans;
        dfs(ans,adj,isvisited,0);
        return ans;
    }
};