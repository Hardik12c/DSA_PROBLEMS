class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<capacity.size();i++){
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int ans=0;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]==0) ans++;
            if(capacity[i]>0 && additionalRocks>=capacity[i]){
                additionalRocks-=capacity[i];
                ans++;
            }
        }
        return ans;
    }
};