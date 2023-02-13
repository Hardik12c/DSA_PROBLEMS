class Solution {
public:
    int cnt(int low,int high){
        return (high-low)/2;
    }
    int countOdds(int low, int high) {
        int cont=0;
        if(low&1 && high&1){
            cont=2+cnt(low+1,high-1);
        }else if(low%2==0&& high%2==0){
            cont=cnt(low,high);
        }else if(low&1 && high%2==0){
            cont=1+cnt(low+1,high);
        }else{
            cont=1+cnt(low,high-1);
        }
        return cont;
    }
};