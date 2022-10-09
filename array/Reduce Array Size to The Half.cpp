class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int,greater<int> > mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        vector<int> v;
        for(auto i:mpp){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int count=0;
        int prog=arr.size();
        for(int i=0;i<v.size();i++){
            count++;
            if(prog-v[i]<=arr.size()/2){
                break;
            }
            prog=prog-v[i];
        }
        return count;
    }
};