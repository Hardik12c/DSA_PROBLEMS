class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int deficient=0;
        int balance=0;
        int start=0;
        for(int i=0;i<n;i++){
            balance+=gas[i]-cost[i];
            if(balance<0){
                deficient+=balance;
                balance=0;
                start=i+1;
            }          
        }
        if(balance+deficient>=0){
            return start;
        }else{
            return -1;
        }
     }
};