class Solution {
public:
    int clumsy(int n) {
        int ans=n;
        n--;
        if(n>0){
            ans*=n;
            n--;
        }
        if(n>0){
            ans/=n;
            n--;
        }
        if(n>0){
            ans+=n;
            n--;
        }
        while(n>0){
        cout<<n<<endl;
            int sum=n;
            n--;
            if(n>0){
                sum*=n;
                n--;
            }
            if(n>0){
                sum/=n;
                n--;
            }
            if(n>0){
                sum-=n;
                n--;
            }
            ans-=sum;
        }
        return ans;
    }
};