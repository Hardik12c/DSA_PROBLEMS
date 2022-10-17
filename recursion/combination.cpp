class Solution {
public:
    void findposs(vector<int> candidates,int target,int i,vector<vector<int>> &ans,vector<int> store){
        if(i>=candidates.size()){
            if(target==0) ans.push_back(store);
            return;
        }
        if(candidates[i]<=target){
            store.push_back(candidates[i]);
            findposs(candidates,target-candidates[i],i,ans,store);
            store.pop_back();
        } 
        findposs(candidates,target,i+1,ans,store);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        vector<vector<int>> ans;
        vector<int> store;
        findposs(candidates,target,i,ans,store);
        return ans;
    }
};