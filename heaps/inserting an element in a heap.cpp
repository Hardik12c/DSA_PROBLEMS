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
};
int main(){
    heap h;
    h.add(1);
    h.add(4);
    h.add(2);
    h.add(3);
    h.add(9);
    h.add(7);
    h.add(8);
    h.add(10);
    h.add(14);
    h.add(16);
    h.print();
    return 0;
}