class Solution {
public:
    void dfs(vector<vector<int>> graph,vector<vector<int>> &ans, vector<int> temp,int node){
        if(node==graph.size()-1){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<graph[node].size();i++){
            temp.push_back(graph[node][i]);
            dfs(graph,ans,temp,graph[node][i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(graph,ans,temp,0);
        return ans;
    }
};