int searchInsert(vector<int>& arr, int m)
{
	int n=arr.size();
	int s=0;
	int e=n-1;
	int mid=s+(e-s)/2;
	while(s<=e){
		if(arr[mid]==m){
			return mid;
		}else if(arr[mid]>m){
			e=mid-1;
		}else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return mid;
}