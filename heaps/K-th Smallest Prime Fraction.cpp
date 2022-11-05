class store{
    public:
    int a;
    int b;
    int ai;
    int bi;
    store(int a,int b,int ai,int bi){
        this->a=a;
        this->b=b;
        this->ai=ai;
        this->bi=bi;
    }
};
class compare{
    public:
    bool operator()(store* a,store* b){
        float m=float(a->a)/a->b;
        float n=float(b->a)/b->b;
        return m>n;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<store*,vector<store*>,compare> pq;
        vector<int> ans;
        int i=0;            
        while(i<k && i<arr.size()){
            pq.push(new store(arr[i],arr[arr.size()-1],i,arr.size()-1));
            i++;
        }
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            k--;
            if(temp->bi-1>temp->ai){
                pq.push(new store(temp->a,arr[temp->bi-1],temp->ai,temp->bi-1));
            }
            if(k==0){
                ans.push_back(temp->a);
                ans.push_back(temp->b);
                break;
            }
        }
        return ans;
    }
};