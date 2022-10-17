void sumsb(vector<int> arr,int ind,vector<int> &ans,vector<int> store){
    if(ind>=arr.size()){
        int sum=0;
        for(int i=0;i<store.size();i++){
            sum+=store[i];
        }
        ans.push_back(sum);
        return;
    }
    
    // take the number
    store.push_back(arr[ind]);
    sumsb(arr,ind+1,ans,store);
    // not take.
    store.pop_back();
    sumsb(arr,ind+1,ans,store);
}