class Solution {
public:
    void recurse(int index,string tiles,string temp,unordered_map<string,int> &mpp){
        if(index>=tiles.length()){
            if(temp.length()>0) mpp[temp]++;
            return;
        }
        int count=0;
        for(int i=index;i<tiles.length();i++){
            if(i!=index && tiles[i]==tiles[i-1]) continue;
            temp+=tiles[i];
            swap(tiles[i],tiles[index]);
            recurse(index+1,tiles,temp,mpp);
            temp.pop_back();
            swap(tiles[i],tiles[index]);
        }
        return recurse(index+1,tiles,temp,mpp);

    }
    int numTilePossibilities(string tiles) {
        unordered_map<string,int> mpp;
        recurse(0,tiles,"",mpp);
        return mpp.size();
    }
};