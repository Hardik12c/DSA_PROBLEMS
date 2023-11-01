int getPagesCount(vector<int> arr,int numberOfPages){
    int studCount=1;
    int initialPageCount=0;
    for(int i=0;i<arr.size();i++){
        if(initialPageCount+arr[i]>numberOfPages){
            studCount++;
            initialPageCount=0;
        }
        initialPageCount+=arr[i];
    }
    return studCount;
}

int findPages(vector<int> arr, int n, int m) {
    if(m>n) return -1;
    int s=*max_element(arr.begin(),arr.end());
    int e=accumulate(arr.begin(),arr.end(),0);
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int studCount= getPagesCount(arr,mid);
        if(studCount<=m){
            ans= min(mid,ans);
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans==INT_MAX?-1:ans;
}