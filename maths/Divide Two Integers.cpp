class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=1;
        if(dividend<0 && divisor<0){
            sign=1;
        }else if(dividend<0 || divisor<0) {
            sign=-1;
        }
        long long int divide=abs(dividend);
        long long int divis=abs(divisor);

        
        long long int ans=0;
        if(divis==1){
            ans=divide;
        }else{
            while(divide>=divis){
                divide-=divis;
                ans++;            
            }
        }
        ans*=sign;
        if(ans>2147483647) return 2147483647;

        return (ans);
    }
};