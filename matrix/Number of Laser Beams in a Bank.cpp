class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCount=0;
        int ans=0;
        for(int i=0;i<bank.size();i++){
            if(prevCount>0){
                int count=0;
                for(int j=0;j<bank[i].length();j++){
                    if(bank[i][j]=='1') count++;
                }
                ans+=count*prevCount;
                if(count>0) prevCount=count;
            }else{
                for(int j=0;j<bank[i].length();j++){
                    if(bank[i][j]=='1') prevCount++;
                }
            }

        }
        return ans;
    }
};