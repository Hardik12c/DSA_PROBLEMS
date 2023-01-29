#include <bits/stdc++.h>
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adj[v];
	for(int i=0;i<edges.size();i++){
		adj[edges[i][0]].push_back(edges[i][1]);
	}
	vector<int> indegree(v,0);

	for(int i=0;i<v;i++){
		for(auto it: adj[i]){
			indegree[it]++;
		}
	}
	queue<int> qu;
	for(int i=0;i<v;i++){
		if(indegree[i]==0) qu.push(i);
	}
	int cnt=0;

	while(!qu.empty()){
		int node=qu.front();
		qu.pop();
		cnt++;


		for(auto it:adj[node]){
			indegree[it]--;

			if(indegree[it]==0) qu.push(it);
		}
	}
	if(cnt!=v) return true;

	return false;
}
