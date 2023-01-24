class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,int> mpp;
        for(int i=0;i<restricted.size();i++){
            mpp[restricted[i]]++;
        }
        queue<int> qu;
        qu.push(0);
        vector<int> visited(n,0);
        visited[0]=1;
        int ans=1;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            for(auto it:adj[node]){
                if(mpp.find(it)==mpp.end()&&!visited[it]){
                    visited[it]=1;
                    ans++;
                    qu.push(it);
                }
            }
        }
        return ans;
    }
};