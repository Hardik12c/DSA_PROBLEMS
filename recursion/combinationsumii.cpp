class Solution {
public:
    void combinations(vector<int> candidates,int target, vector<vector<int>> &ans,vector<int> store,int ind){
        if(target==0){
            ans.push_back(store);
            return;
        }
        
        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target) break;
            if(i!=ind && candidates[i]==candidates[i-1]) continue;

            store.push_back(candidates[i]);
            combinations(candidates,target-candidates[i],ans,store,i+1);
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        int ind=0;
        vector<vector<int>> ans;
        vector<int> store;
        combinations(candidates,target,ans,store,ind);
        return ans;
    }
};