class store{
    public:
    int data;
    int row;
    int col;
    store(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<store*,vector<store*>,compare> pq;

        int mn=INT_MAX;int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push(new store(nums[i][0],i,0));
            mx=max(mx,nums[i][0]);
            mn=min(mn,nums[i][0]);
        }
        int ansmx=mx;int ansmn=mn;
        while(!pq.empty()){
            // first pop out the element from pq and store it
            auto temp=pq.top();
            pq.pop();

            // if next element present just push it
            if(temp->col+1<nums[temp->row].size()){
                pq.push(new store(nums[temp->row][temp->col+1],temp->row,temp->col+1));
                mx=max(mx,nums[temp->row][temp->col+1]);
            }
            // else we reach the end of a list and just break
            else break;
            // now we will check if difference of updated max and min is less than previous
            if(mx-pq.top()->data<ansmx-ansmn){
                ansmx=mx;
                ansmn=pq.top()->data;
            }
        }
        vector<int> ans;
        ans.push_back(ansmn);
        ans.push_back(ansmx);
        return ans; 
    }
};