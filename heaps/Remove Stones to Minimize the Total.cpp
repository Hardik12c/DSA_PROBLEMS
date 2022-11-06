class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k>0){
            int num=pq.top();
            pq.pop();
            if(num&1) num=(num/2)+1;
            else num/=2;
            pq.push(num);
            k--;
        }
        int ans=0;
        while(!pq.empty()){
           ans+=pq.top();
           pq.pop();
        }
        return ans;
    }
};