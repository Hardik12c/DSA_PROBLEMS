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
class compare{
    public:
    bool operator()(store* a,store* b){
        return a->data>b->data;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<store*,vector<store*>,compare> pq;
        for(int i=0;i<matrix.size();i++){
            pq.push(new store(matrix[i][0],i,0));
        }
        int ans;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            k--;
            if(temp->j+1<matrix[temp->i].size()){
                pq.push(new store(matrix[temp->i][temp->j+1],temp->i, temp->j+1));
            }
            if(k==0){
                ans=temp->data;
                break;
            }
        }
        return ans;
    }
};