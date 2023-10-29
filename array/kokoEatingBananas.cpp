class Solution {
public:
    long long int getTotalHours(int count,vector<int> piles){
        long long int hrs=0;
        for(int i=0;i<piles.size();i++){
            hrs+=piles[i]/count;
            hrs+=piles[i]%count>0?1:0;
        }
        cout<<hrs<<endl;
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(start<=end){
            int mid=start+(end-start)/2;
            long long int hrs=getTotalHours(mid,piles);
            if(hrs<=h){
                if(mid<ans) ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};