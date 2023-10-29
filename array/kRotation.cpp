int findKRotation(vector<int> &arr){
    int pivotIndex=0;
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>arr[mid+1]){
            // cout<<"hello"<<endl;
            pivotIndex=mid+1;
            break;
        }else if(mid-1>=0 && arr[mid]<arr[mid-1]){
            pivotIndex=mid;
            break;
        }else if(arr[mid]<arr[s]){
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return pivotIndex;
}