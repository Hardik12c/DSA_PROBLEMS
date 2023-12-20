class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int x=INT_MAX,y=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<x){
                if(prices[i]<y){
                    x=y;
                    y=prices[i];
                }else x=prices[i];
            }
        }
        return (x+y)>money?money:(money-x-y);
    }
};