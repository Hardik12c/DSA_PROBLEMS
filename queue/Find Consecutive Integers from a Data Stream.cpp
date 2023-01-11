class DataStream {
private:
    queue<int> qu;
    unordered_map<int,int> mpp;
    int k;
    int value;
public:
    DataStream(int value, int k) {
        this->k=k;
        this->value=value;
    }
    
    bool consec(int num) {
        qu.push(num);
        mpp[num]++;
        if(qu.size()<k){
            return false;
        }else{
            if(qu.size()>k){
                mpp[qu.front()]--;
                qu.pop();
            }
            return mpp[value]==k;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */