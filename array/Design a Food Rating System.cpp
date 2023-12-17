class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>> mpp1;
    unordered_map<string,string> mpp;
    unordered_map<string,int> mpp2;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mpp[foods[i]]=cuisines[i];
            mpp1[cuisines[i]].insert({-ratings[i],foods[i]});
            mpp2[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        mpp1[mpp[food]].erase({-mpp2[food],food});
        mpp1[mpp[food]].insert({-newRating,food});
        mpp2[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(mpp1[cuisine])->second;
    }
};