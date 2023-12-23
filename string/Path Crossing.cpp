namespace std {
    template <>
    struct hash<std::pair<int, int>> {
        size_t operator()(const std::pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
}
class Solution {
public:

    bool isPathCrossing(string path) {
        pair<int,int> p={0,0};
        unordered_map<pair<int,int>,int> mpp;
            mpp[p]++;
        for(int i=0;i<path.size();i++){
            if(path[i]=='N') p.second++;
            else if(path[i]=='E') p.first++;
            else if(path[i]=='S') p.second--;
            else p.first--;
            if(mpp.find(p)!=mpp.end()) return true;
            mpp[p]++;
        }   
        return false;
    }
};