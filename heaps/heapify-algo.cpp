#include "iostream"

using namespace std;

void heapify(int arr[],int i,int n){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    int size=5;
    for(int i=size/2;i>0;i--){
        heapify(arr,i,size);
    }
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}