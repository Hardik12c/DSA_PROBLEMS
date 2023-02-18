class Solution {
public:
    int solve(int n,vector<int> &dp){
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        if(n&1){
            return dp[n]=1+solve(((3*n)+1),dp);
        }
        return dp[n]= 1+solve(n/2,dp);
    }
    static bool compare(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> dp(1000001,-1);

        vector<pair<int,int>> order;
        for(int i=lo;i<=hi;i++){
            int num=solve(i,dp);
            order.push_back({i,num});
        }
        sort(order.begin(),order.end(),compare);
        for(int i=0;i<order.size();i++) cout<<i<<" "<<order[i].first<<" "<<order[i].second<<endl;
        return order[k-1].first;
    }
};