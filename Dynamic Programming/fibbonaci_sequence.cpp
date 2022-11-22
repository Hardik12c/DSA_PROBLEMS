#include <iostream>
#include <vector>
using namespace std;
int fibbonaci(int n, vector<int> dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];

    return dp[n]=fibbonaci(n-1,dp)+fibbonaci(n-2,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibbonaci(n,dp);
    return 0;
}