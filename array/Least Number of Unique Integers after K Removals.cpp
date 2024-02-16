class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        vector<pair<int,int>> vc;
        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i])==mpp.end()){
                mpp[arr[i]]=vc.size();
                vc.push_back({1,arr[i]});
            }else{
                vc[mpp[arr[i]]].first++;
            }
        }
        sort(vc.begin(),vc.end());
        int ans=vc.size();
        for(int i=0;i<vc.size();i++){
            if(vc[i].first>k){
                return ans;
            }
            ans--;
            k-=vc[i].first;
        }
        return 0;
    }
};