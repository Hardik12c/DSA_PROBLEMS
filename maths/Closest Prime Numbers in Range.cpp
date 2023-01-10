class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2,-1);
        int prev=-1,next=-1;
        int var;
        int mn=INT_MAX;
        if(left<2) left=2;
        for(int i=left;i<=right;i++){
            int num=i;
            bool flag=true;
            for(int j=2;j<=sqrt(num);j++){
                if(num%j==0){
                    flag=false;
                    break;
                }
            }

            if(flag){
                if(next==-1){
                    next=num;
                    var=num;
                }else if((num-var)<mn){
                    mn=num-var;
                    prev=var;
                    next=num;
                }
                var=num;
            }
            if(mn<3) break;
        }
        if(prev!=-1 && next!=-1){
            ans[0]=prev;
            ans[1]=next;
        }
        return ans;
    }
};