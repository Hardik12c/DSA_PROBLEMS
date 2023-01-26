class Solution {
public:
    bool check(int n,vector<vector<int>>& graph, vector<int> &color){
        queue<int> qu;
        qu.push(n);
        color[n]=0;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();

            for(int i=0;i<graph[node].size();i++){
                if(color[graph[node][i]]==-1){
                    color[graph[node][i]]=1-color[node];
                    qu.push(graph[node][i]);
                }else if(color[graph[node][i]]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> color(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(check(i,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};