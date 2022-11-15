class trienode{
    public:
    char data;
    trienode* children[26];
    int cp;
    trienode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        cp=0;
    }
};
class trie{
    private:
    trienode* root;
    public:
    trie(){
        root=new trienode('\0');
    }
    
    void insert(trienode* root,string s){
        if(s.length()==0){
            return;
        }
        int index=s[0]-'a';
        
        if(root->children[index]==NULL){
            root->children[index]=new trienode(s[0]);
            root->cp++;
        }
        root=root->children[index];
        insert(root,s.substr(1));
    }
    void insertintrie(string s){
        insert(root,s);
    }
    void getans(trienode* root,string s,string &ans){
        if(s.length()==0){
            return;
        }
        int index=s[0]-'a';
        if(root->cp>1){
            return;
        }
        ans+=s[0];
        getans(root->children[index],s.substr(1),ans);
    }
    string prefix(string s,int size){
        string ans="";
        getans(root,s,ans);
        return ans;
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    trie* t=new trie();
    for(int i=0;i<arr.size();i++){
        t->insertintrie(arr[i]);
    }
    return t->prefix(arr[0],arr.size());
}