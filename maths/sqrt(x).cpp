class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        int ans=0;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            long long int sq=mid*mid;
            if(sq==x){
                ans=mid;
                break;
            }else if(sq<x){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};