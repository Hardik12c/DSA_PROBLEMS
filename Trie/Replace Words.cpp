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
    
    bool search(string s,string &ans){
        trienode* curr=root;
        for(int i=0;i<s.length();i++){
            if(curr->isterminal){
                break;
            }
            int index=s[i]-'a';
            if(curr->children[index]==NULL){
                return false;
            }
            ans+=s[i];
            curr=curr->children[index];
        }
        return true;
    }

};class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        trie* t=new trie();
        
        for(int i=0;i<dictionary.size();i++){
            t->insert(dictionary[i]);
        }
        string ans="";
        string k="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' ' || sentence[i]=='\0'){
                string temp="";
                if(t->search(k,temp)){
                    k=temp;
                }
                ans+=k;
                ans+=' ';
                k="";
            }else k+=sentence[i];
            
        }
        string temp="";
        if(t->search(k,temp)){
            k=temp;
        }
        ans+=k;
        return ans;
    }
};