class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        int sum=0;
        int i=1;
        recurse(ans,v,sum,i,n,k);
        return ans;
    }
    void recurse(vector<vector<int>> &ans,vector<int> arr,int sum,int i,int n,int k){
        if(sum>n) return;
        if(arr.size()==k){
            if(sum==n){
                ans.push_back(arr);
            }
            return;
        }
        for(int j=i;j<=9;j++){
            arr.push_back(j);
            
            recurse(ans,arr,sum+j,j+1,n,k);
            
            arr.pop_back();
        }
    }
};
