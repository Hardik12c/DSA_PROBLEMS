class Solution {
public:
    int countbouquets(int days,int k,vector<int> bloomDay){
        int ans=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                count++;
            }else{
                ans+=count/k;
                count=0;
            }
        }
        ans+=count/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=INT_MAX;
        int start=1;
        int end=*max_element(bloomDay.begin(),bloomDay.end());
        while(start<=end){
            int mid=start+(end-start)/2;
            int bouqueCount=countbouquets(mid,k,bloomDay);
            if(bouqueCount>=m){
                ans = min(ans,mid);
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
}; 