class Solution{
public:
    int noofways(int i,int j,int istrue,string s,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        
        if(i==j){
            if(istrue) return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
        int ways=0;
        for(int k=i+1;k<=j-1;k+=2){
            int lt=noofways(i,k-1,1,s,dp);
            int rt=noofways(k+1,j,1,s,dp);
            int lf=noofways(i,k-1,0,s,dp);
            int rf=noofways(k+1,j,0,s,dp);
            
            if(s[k]=='&'){
                if(istrue){
                    ways+=(lt*rt);
                }else{
                    ways+=(lt*rf)+(lf*rt)+(lf*rf);
                }
            }else if(s[k]=='|'){
                if(istrue){
                    ways+=(lt*rt)+(lt*rf)+(lf*rt);
                }else{
                    ways+=(lf*rf);
                }
            }else{
                if(istrue){
                    ways+=(lt*rf)+(lf*rt);
                }else{
                    ways+=(lt*rt)+(lf*rf);
                }
            }
        }
        return dp[i][j][istrue]=ways%1003;
    }
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return noofways(0,N-1,1,S,dp);
    }
};