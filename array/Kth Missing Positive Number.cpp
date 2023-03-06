class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++) mpp[arr[i]]++;
        int num=1;
        while(k!=0){

            if(mpp.find(num)==mpp.end()){
                k--;
            }
            num++;
        }
        return --num;
    }
};