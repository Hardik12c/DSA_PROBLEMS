class store{
  public:
  int data;
  int i;
  int j;
  store(int data,int row,int col){
      this->data=data;
      i=row;
      j=col;
  }
};
struct compare{
    bool operator()(store* a,store* b){
        return a->data>b->data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<store*,vector<store*>,compare> pq;
        for(int i=0;i<K;i++){
            store* temp= new store(arr[i][0],i,0);
            pq.push(temp);
        }
        
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            ans.push_back(temp->data);
            if((temp->j)+1<arr[temp->i].size()){
                store* newstore=new store(arr[temp->i][(temp->j)+1],temp->i,(temp->j)+1);
                pq.push(newstore);
            }
        }


        return ans;
        
    }
};