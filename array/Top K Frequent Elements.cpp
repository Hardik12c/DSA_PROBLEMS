class Solution {
public:
    static bool compare(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> pairvector;
        for(auto i:mpp){
            pairvector.push_back({i.first,i.second});
        }
        sort(pairvector.begin(),pairvector.end(),compare);
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pairvector[i].first);
        }
        return ans;
    }
};
//using priority queue
class pairs{
    public:
    int num;
    int freq;
    pairs(int num,int freq){
        this->num=num;
        this->freq=freq;
    }
};
class compare{
    public:
  bool operator()(pairs* a,pairs* b){
      return a->freq>b->freq;
  }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pairs*,vector<pairs*>,compare> pq;
        for(auto i:mpp){
            if(pq.size()<k){
                pairs* temp=new pairs(i.first,i.second);
                pq.push(temp);
            }else if(i.second>pq.top()->freq){
                pq.pop();
                pairs* temp=new pairs(i.first,i.second);
                pq.push(temp);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top()->num);
            pq.pop();
        }
        return ans;
    }
};