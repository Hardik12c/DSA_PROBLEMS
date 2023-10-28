

void firstOccurence(vector<int> arr,int s,int e,int x,int &firstOcc){
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==x){
			firstOcc=mid;
			e=mid-1;
		}else if(arr[mid]<x){
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
}
void lastOccurence(vector<int> arr,int s,int e, int x, int &lastOcc){
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==x){
			lastOcc=mid;
			s=mid+1;
		}else if(arr[mid]<x){
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
}
int count(vector<int>& arr, int n, int x) {
	int firstocc=-1;
	int lastocc=-1;
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==x){
			firstocc=mid;
			lastocc=mid;
			firstOccurence(arr, s, mid-1, x,firstocc);
			lastOccurence(arr, mid+1,  e, x, lastocc);
			break;
		}else if(arr[mid]<x){
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	return firstocc==-1&&lastocc==-1?0:lastocc-firstocc+1;
}
