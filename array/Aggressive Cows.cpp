class Solution {
public:
    bool canWePlace(int distance,int k, vector<int> stalls){
        int numOfCowsPlaced=1;
        int lastCowPlace=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastCowPlace>=distance){
                numOfCowsPlaced++;
                lastCowPlace=stalls[i];
            }
        }
        // cout<<numOfCowsPlaced<<"HELLO"<<endl;
        if(numOfCowsPlaced>=k){
            return true;
        }
        return false;
        
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int s=1;
        int e=stalls[stalls.size()-1]-stalls[0];
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(canWePlace(mid,k,stalls)){
                s=mid+1;
                ans=mid;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};