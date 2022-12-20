class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]=i;
        }
        for(int i=0;i<arr.size();i++){
            if(mpp.find(arr[i]*2)!=mpp.end() && mpp[arr[i]*2]!=i){
                cout<<arr[i]<<endl;
                return true;
            }
        }
        return false;
    }
};