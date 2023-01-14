class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        queue<int> qu;
        vector<int> isvisited(V,0);
        qu.push(0);
        isvisited[0]=1;
        
        while(!qu.empty()){
            int num=qu.front();
            qu.pop();
            ans.push_back(num);
            for(auto it:adj[num]){
                if(!isvisited[it]){
                    isvisited[it]=1;
                    qu.push(it);
                }
            }
        }
        return ans;
    }
};