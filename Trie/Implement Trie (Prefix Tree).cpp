class Trienode{
public:
    char data;
    Trienode* children[26];
    bool isterminal;
    Trienode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class Trie {
public:
    Trienode *root;
    Trie() {
        root=new Trienode('\0');
    }
    
    void insert(string word) {
        insertintrie(word,root);
    }
    void insertintrie(string word,Trienode* root){
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        int index=word[0]-'a';
        
        if(root->children[index]!=NULL){
            root=root->children[index];
        }else{
            Trienode* temp=new Trienode(word[0]);
            root->children[index]=temp;
            root=temp;
        }
        insertintrie(word.substr(1),root);
    }
    bool searchintrie(string word,Trienode* root,bool flag){
        if(word.length()==0){
            if(flag) return root->isterminal;
            return true;
        }
        int index=word[0]-'a';

        if(root->children[index]!=NULL){
            root=root->children[index];
        }else return false;

        return searchintrie(word.substr(1),root,flag);
    }
    bool search(string word) {
        return searchintrie(word,root,true);
    }
    
    bool startsWith(string prefix) {
        return searchintrie(prefix,root,false);
    }
};