class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> mpp;
        for(int i=0;i<changed.size();i++){
            mpp[changed[i]]++;
        }
        vector<int>ans;
        for(auto it:mpp){
            int num=it.first;
            if(mpp.find(num*2)!=mpp.end() && mpp[num]>0){
                if(num==0){
                    if(mpp[num]%2==0){
                        int n=mpp[num]/2;
                        for(int i=0;i<n;i++) ans.push_back(0);
                    }
                }
                else{
                    while(mpp[num]>0 && mpp[num*2]>0){
                        cout<<num<<endl;
                        ans.push_back(num);
                        mpp[num]--;
                        mpp[num*2]--;
                    }
                }
            }
        }
        if(changed.size()&1|| ans.size()!=changed.size()/2){
            vector<int> temp;
            return temp;
        }
        return ans;
    }
};