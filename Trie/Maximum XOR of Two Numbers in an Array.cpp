class trienode{
    public:
    trienode* next[2];
    trienode(){
        next[0]=NULL;
        next[1]=NULL;
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
            if(curr->next[bit]==NULL){
                curr->next[bit]=new trienode();
            }
            curr=curr->next[bit];
        }
    }
    int maxxor(int num){
        trienode* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->next[1-bit]!=NULL){
                ans+=(1<<i);
                curr=curr->next[1-bit];
            }else{
                curr=curr->next[bit];
            }
        }
        return ans;
    }    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie* t= new trie();
        for(int i=0;i<nums.size();i++){
            t->insert(nums[i]);
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,t->maxxor(nums[i]));
        }
        return ans;
    }
};