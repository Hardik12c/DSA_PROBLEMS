class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> qu;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }
        vector<int> ans;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) qu.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};