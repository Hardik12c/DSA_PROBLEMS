class Solution {
public:
    int numDays(vector<int> weights,int weight,int days){
        int sum=0;
        int num=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>weight) return days+1;
            if(sum+weights[i]>weight){
                sum=0;
                num++;
            }
            sum+=weights[i];
        }
        cout<<sum<<" "<<weight<<" "<<num<<endl;
        if(sum>weight){
            return days+1;
        }
        return num+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for (int i=0;i<weights.size();i++) sum+=weights[i];
        int s=1;
        int e=sum;
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            int numberOfDays=numDays(weights,mid,days);
            if(numberOfDays<=days){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};