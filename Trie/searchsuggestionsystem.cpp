class trienode{
    public:
    trienode* children[26];
    bool isterminal;
    trienode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class trie{
    private:
    trienode* root;
    public:
    trie(){
        root=new trienode();
    }
    
    void insert(string s){
        trienode* curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new trienode();
            }
            curr=curr->children[index];
        }
        curr->isterminal=true;
    }
    
    void addsuggestion(trienode* root,vector<string>&temp,string prefix,int &it){
        if(it>2) return;
        
        if(root->isterminal==true){
            temp.push_back(prefix);
            it++;
        }
        
        
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                prefix+=i+'a';
                addsuggestion(root->children[i],temp,prefix,it);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> printsuggestion(string s){
        trienode* curr=root;
        
        string prefix="";
        
        vector<vector<string>> ans;
        
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            
            if(curr->children[index]==NULL){
                while(i<s.length()){
                    ans.push_back({});
                    i++;
                }
            }else{
                prefix+=s[i];
                curr=curr->children[index];
                vector<string> temp;
                int it=0;
                
                addsuggestion(curr,temp,prefix,it);
                
                ans.push_back(temp);
            }
        }
        return ans;
    }
    
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trie* tr=new trie();
        for(int i=0;i<products.size();i++){
            tr->insert(products[i]);
        }
        return tr->printsuggestion(searchWord);
    }
};