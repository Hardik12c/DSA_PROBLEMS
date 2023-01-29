class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        

        queue<int> qu;
        for(int i=0;i<numCourses;i++){
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
        if(ans.size()!=numCourses){
            vector<int> temp;
            return temp;
        }
        return ans;
    }
};