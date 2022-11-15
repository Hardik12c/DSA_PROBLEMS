class trienode{
    public:
    trienode* data[2];
    trienode(){
        data[0]=NULL;
        data[1]=NULL;
    }
};
class trie{
    private:
    trienode* root;
    public:
    trie(){
        root=new trienode();
    }

    void insert(int num){
        trienode* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->data[bit]==NULL){
                curr->data[bit]=new trienode();
            }
            curr=curr->data[bit];
        }
    }

    int maxxor(int num){
        trienode* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->data[1-bit]!=NULL){
                ans+=(1<<i);
                curr=curr->data[1-bit];
            }else{
                curr=curr->data[bit];
            }
        }
        return ans;
    }
};
bool compare(pair<int,pair<int,int>> v1,pair<int,pair<int,int>> v2){
    return v1.second.second<v2.second.second;
}
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        sort(nums.begin(),nums.end());
        trie* tr=new trie();

        // putting pairwise in querieswithi with index
        vector<pair<int,pair<int,int>>> querieswithi;
        for(int i=0;i<queries.size();i++){
            querieswithi.push_back({i,{queries[i][0],queries[i][1]}});
        }
        sort(querieswithi.begin(),querieswithi.end(),compare);
        int it=0;
        for(int i=0;i<queries.size();i++){
            int num=querieswithi[i].second.first;
            int n=querieswithi[i].second.second;
            int index=querieswithi[i].first;
            while(nums[it]<=n && it<nums.size()){
                tr->insert(nums[it]);
                it++;
            }
            if(it==0) ans[index]=-1;
            else {
                int mx=tr->maxxor(num);
                ans[index]=mx;
            }
        }
        return ans;
    }
};