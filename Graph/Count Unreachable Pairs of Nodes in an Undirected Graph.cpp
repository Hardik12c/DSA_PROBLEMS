class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &isvisited,int node,int &count){
        isvisited[node]=1;
        for(auto it:adj[node]){
            if(!isvisited[it]){
                count++;
                dfs(adj,isvisited,it,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long ans=0;
        int count=0;
        vector<int> isvisited(n,0);
        for(int i=0;i<n;i++){
            if(!isvisited[i]){
                int temp=1;
                dfs(adj,isvisited,i,temp);
                long long visit=temp;
                long long notvisit=n-count-temp;
                count+=temp;
                ans+=(visit*notvisit);
            }
        }
        return ans;
    }
};