class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>qu;
	    for(int i=0;i<V;i++){
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
	    return ans;
	}
};