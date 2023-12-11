class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int occurence=arr.size()/4;
        cout<<occurence<<endl;
        int num=arr[0];
        int count=1;
        for(int i=1;i<arr.size();i++){
            if(count>occurence){
                return num;
            }
            if(arr[i]==arr[i-1]){
                count++;
            }else{
                count=1;
                num=arr[i];
            }
        }
        return num;
    }
};