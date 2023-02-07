class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mxcnt=0;
        unordered_map<int,int> mpp;
        int i=0;
        while(i<fruits.size()){
            if(mpp.size()<2 || mpp.find(fruits[i])!=mpp.end()){
                mpp[fruits[i]]++;
            }else{
                break;
            }
            i++;
        }
        for(auto it:mpp){
            mxcnt+=it.second;
        }
        int j=0;
        while(i<fruits.size()){
            int cnt=0;
            mpp[fruits[j]]--;
            if(mpp[fruits[j]]==0){
                mpp.erase(fruits[j]);
            }
            j++;
            while(i<fruits.size()){
                if(mpp.size()<2 || mpp.find(fruits[i])!=mpp.end()){
                    mpp[fruits[i]]++;
                }else{
                    break;
                }
                i++;
            }
            for(auto it:mpp){
                cnt+=it.second;
            }
            mxcnt=max(cnt,mxcnt);
        }
        return mxcnt;
    }
};