#include "bits/stdc++.h"
double minimiseMaxDistance(vector<int> &arr, int k){
	vector<int> howMany(arr.size()-1,0);
	priority_queue<pair<long double,int>> pq;
	for(int i=0;i<arr.size()-1;i++){
		pq.push({(arr[i+1]-arr[i]),i});
	}
	for(int i=0;i<k;i++){
		auto t=pq.top();pq.pop();
		howMany[t.second]++;
		int diff=arr[t.second+1]-arr[t.second];
		pq.push({((long double)diff/((long double)howMany[t.second]+1)),t.second});
	}
	return pq.top().first;
}
