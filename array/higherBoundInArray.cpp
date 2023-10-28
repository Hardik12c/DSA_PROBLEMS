int upperBound(vector<int> &arr, int x, int n){
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]<=x){
			s=mid+1;
		}else{
			ans=mid;
			e=mid-1;
		}
	}
	return ans==-1?n:ans;
}