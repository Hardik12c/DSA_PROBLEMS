class compare{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        float m=float(a.first)/a.second;
        float n=float(b.first)/b.second;
        return m<n;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(pq.size()<k) pq.push({arr[i],arr[j]});
                
                else{
                    float m=float(pq.top().first)/pq.top().second;
                    float n=float(arr[i])/arr[j];
                    if(n<m){
                        pq.pop();
                        pq.push({arr[i],arr[j]});
                    }
                }
            }
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        ans.push_back(pq.top().second);
        return ans;
    }
};