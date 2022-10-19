#include "iostream"
#include "vector"
#include "math.h"

using namespace std;
class heap{
    private:
    vector<int> arr;
    int index;
    public:
    heap(){
        arr.push_back(-1);
        index=1;
    }

    void add(int val){
        arr.push_back(val);
        int i=index;
        while(i>1){
            int k=i/2;
            if(arr[k]<arr[i]){
                swap(arr[k],arr[i]);
                i=k;
            }
            else{
                break;
            }
        }
        index++;
    }
    void print(){
        for(int i=1;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deletefromheap(){
        if(arr.size()==0) return;
        swap(arr[1],arr[index-1]);
        arr.erase(arr.begin()+index-1);
        index--;
        int i=1;
        while(i<arr.size()){
            int leftindex=2*i;
            int rightindex=2*i+1;
            if(leftindex<arr.size() && arr[leftindex]>arr[i]){
                swap(arr[leftindex],arr[i]);
                if(rightindex<arr.size() && arr[rightindex]>arr[i]){
                    swap(arr[rightindex],arr[i]);
                    i=rightindex;
                }
                i=leftindex;
            }else{
                return;
            }
        }
    }
};
int main(){
    heap h;
    h.add(55);
    h.add(53);
    h.add(54);
    h.add(50);
    h.add(49);
    h.add(40);
    h.add(30);
    h.print();
    h.deletefromheap();
    h.print();
    return 0;
}