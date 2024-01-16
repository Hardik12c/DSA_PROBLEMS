class RandomizedSet {
public:
    unordered_map<int,int> mpp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mpp.find(val)==mpp.end()){
            mpp[val]++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mpp.find(val)!=mpp.end()){
            mpp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int ind=rand()%mpp.size();
        auto it=mpp.begin();
        advance(it,ind);
        return it->first;
    }
};
