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
    void printsuggestion(trienode* root,vector<string>& temp,string prefix){
        if(root->isterminal){
            temp.push_back(prefix);
        }
        for(int i=0;i<26;i++){
            trienode* next=root->children[i];
            if(next!=NULL){
                prefix+=i+'a';
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> findsuggestion(string s){
        trienode* prev=root;
        vector<vector<string>> ans;
        string prefix="";
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            prefix+=s[i];
            if(prev->children[index]==NULL){
                break;
            }else{
                prev=prev->children[index];
                vector<string> temp;
                printsuggestion(prev,temp,prefix);
                ans.push_back(temp);
            }
        }
        int size=ans.size();
        for(int i=size;i<=s.length();i++){
            vector<string> temp;
            temp.push_back("0");
            ans.push_back(temp);
        }
        
        return ans;
    }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie* tr=new trie();
        for(int i=0;i<n;i++){
            tr->insert(contact[i]);
        }
        return tr->findsuggestion(s);
    }
};