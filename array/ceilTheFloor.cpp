int lowerBound(vector<int> arr, int n, int x) {
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]>=x){
			ans=arr[mid];
			e=mid-1;
		}else{
			s=mid+1;
		}
	}
	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int,int> p;
	int s=0;
	int e=n-1;
	int ceil=lowerBound(a, n, x);
	int floor=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(a[mid]<=x){
			floor=a[mid];
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	p=make_pair(floor,ceil);
	return p;
}