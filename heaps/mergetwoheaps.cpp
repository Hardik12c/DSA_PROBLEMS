class Solution{
    public:
    void heapify(int i,vector<int> &ans,int n){
        int left=2*i+1;
        int right=2*i+2;
        
        int largest=i;
        if(left<n&&ans[left]>ans[largest]) largest =left;
        if(right<n&&ans[right]>ans[largest]) largest =right;
        
        if(i!=largest){
            swap(ans[i],ans[largest]);
            heapify(largest,ans,n);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
       for(int i=0;i<n;i++){
           ans.push_back(a[i]);
       }
       for(int i=0;i<m;i++){
           ans.push_back(b[i]);
       }
       int size=ans.size();
      for(int i=size/2-1;i>=0;i--){
           heapify(i,ans,size);
      }
        return ans;
    }
};