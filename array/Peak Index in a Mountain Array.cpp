class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        long k,l;
        while(s<e){
            if(mid-1<0){
                k=LONG_MIN;
            }else{
                k=arr[mid-1];
            }
            if(mid+1>arr.size()-1){
                l=LONG_MIN;
            }else{
                l=arr[mid+1];
            }
            if(arr[mid]>k && arr[mid]>l){
                return mid;
            }else if(arr[mid]>k){
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
            
        }
        return mid; 
    }
};