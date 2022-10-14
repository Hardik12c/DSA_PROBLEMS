class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int k=max(a,b);
        k=max(k,c);
        int sum=a+b+c-k;
        if(sum<=k){
            return sum;
        }
        int l=(sum-k)/2;
        return k+l;
    }
};