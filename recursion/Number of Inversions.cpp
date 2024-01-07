int  merge(vector<int> &arr,int left,int mid,int right){
    vector<int> ret;
    int low=left;
    int h=mid+1;
    int cnt=0;
    while(low<=mid && h<=right){
        if(arr[low]<=arr[h]){
            ret.push_back(arr[low]);
            low++;
        }else{
            cnt+=(mid-low+1);
            ret.push_back(arr[h]);
            h++;
        }
    }
    while(low<=mid){
        ret.push_back(arr[low]);
        low++;
    }
    while(h<=right){
        ret.push_back(arr[h]);
        h++;
    }
    for(int i=left;i<=right;i++){
        arr[i]=ret[i-left];
    }
    return cnt;
}
int mergesort(vector<int> &arr,int left,int right){
    int cnt=0;
    if(left>=right) return cnt;
    int mid=left+(right-left)/2;
    cnt+=mergesort(arr,left,mid);
    cnt+=mergesort(arr,mid+1,right);
    cnt+=merge(arr,left,mid,right);
    return cnt;
}
int numberOfInversions(vector<int>&a, int n) {
    return mergesort(a,0,n-1);
}
