class Solution {
public:
    int findindex(int num){
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> mpp;
        for(int i=lowLimit;i<=highLimit;i++){
            if(i<10) mpp[i]++;
            else{
                int index=findindex(i);
                mpp[index]++;
            }
        }
        int ans=INT_MIN;
        for(auto i:mpp){
            if(i.second>ans){ 
            ans=i.second;
            }
        }
        return ans;
    }
};