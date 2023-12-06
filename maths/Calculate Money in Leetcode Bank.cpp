class Solution {
public:
    int totalMoney(int n) {
        int num=-1;
        int number=1;
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            if((count)%7==0){
                number=1;
                num++;
                count=0;
            }
            ans+=number+num;
            number++;
            count++;
        }
        return ans;
    }
};