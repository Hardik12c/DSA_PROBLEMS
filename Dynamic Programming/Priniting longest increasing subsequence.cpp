class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> hash(n);
        vector<int> dp;
        for(int i=0;i<n;i++){
            hash[i]=(i);
            dp.push_back(1);
        }
        int lastindex=0;
        int len=1;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>len){
                len=dp[i];
                lastindex=i;
            }
        }
        vector<int> ans;
        while(hash[lastindex]!=lastindex){
            ans.push_back(arr[lastindex]);
            lastindex=hash[lastindex];
        }
        ans.push_back(arr[lastindex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};