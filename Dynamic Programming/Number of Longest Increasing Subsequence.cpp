class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        int len=1;
        vector<int> count(n,1);
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(1+dp[j]==dp[i]){
                        count[i]+=count[j];
                    }else if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        count[i]=count[j];
                    }
                }
            }
            len=max(len,dp[i]);
        }
        int ans=0;
        for(int i=0;i<count.size();i++){
            if(dp[i]==len){
                ans+=count[i];
            }
        }
        return ans;
    }
};