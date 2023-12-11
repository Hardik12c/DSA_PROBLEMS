class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int low=0;
        int high=piles.size()-1;
        sort(piles.begin(),piles.end());
        int ans=0;
        while(low<high){
            high--;
            ans+=piles[high];
            low++;
            high--;
        }
        return ans;
    }
};