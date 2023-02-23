class MapSum {
public:
    unordered_map<string,int> fullstringmap;
    unordered_map<string,int> mpp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        string temp="";
        if(fullstringmap.find(key)==mpp.end()){
            fullstringmap[key]=val;
            for(int i=0;i<key.size();i++){
                temp+=key[i];
                mpp[temp]+=val;
            }
        }else{
            int num=fullstringmap[key];
            fullstringmap[key]=val;
            for(int i=0;i<key.size();i++){
                temp+=key[i];
                mpp[temp]=mpp[temp]-num+val;
            }
        }
    }
    
    int sum(string prefix) {
        return mpp[prefix];
    }
};