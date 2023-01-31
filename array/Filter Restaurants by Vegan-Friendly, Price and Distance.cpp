class Solution {
public:
static bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second>b.second;
}
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>> temp;
        for(int i=0;i<restaurants.size();i++){
            if(restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance ){
                if(veganFriendly==0 || veganFriendly==restaurants[i][2])
                    temp.push_back({restaurants[i][0],restaurants[i][1]});
            }
        }
        sort(temp.begin(),temp.end(),compare);
        vector<int> ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};