class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> a,pair<int,int>b){
            if(a.first==b.first) return a.second>b.second;
            return a.first>b.first;
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        int i=0;
        long long int startingtime=tasks[0][0];
        while(i<tasks.size() || !pq.empty()){
            while(i<tasks.size() && tasks[i][0]<=startingtime){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(pq.empty())
            {
                startingtime=tasks[i][0];
                continue;
            }
            ans.push_back(pq.top().second);
            startingtime+=pq.top().first;
            pq.pop();
        }
        cout<<i<<" "<<pq.size()<<endl;
        return ans;
    }
};