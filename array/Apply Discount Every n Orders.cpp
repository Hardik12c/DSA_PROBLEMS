class Cashier {
public:
    int n;
    int count=0;
    int discount;
    unordered_map<int,int> mpp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n=n;
        this->discount=discount;
        for(int i=0;i<products.size();i++){
            mpp[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill=0.0;
        for(int i=0;i<amount.size();i++){
            bill+=amount[i]*mpp[product[i]];
        }
        count++;
        if(count==n){
            bill*=(100-discount)/100.0;
            count=0;
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */