int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int maxCount=INT_MIN;
    int ans=-1;
    for(int i=0;i<n;i++){
        int low=0;
        int high=matrix[i].size();
        int mid=low+(high-low)/2;
        int index=-1;
        while(low<=high){
            if(matrix[i][mid]==1){
                index=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        int val=index<0?INT_MIN:(matrix[i].size()-index);
        if(val>maxCount){
            maxCount=val;
            ans=i;
        }
    }
    return ans;
}