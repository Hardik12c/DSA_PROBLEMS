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

//using binary search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return s+k;
    }
};