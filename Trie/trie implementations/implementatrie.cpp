#include <iostream>

using namespace std;
class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isterminal;

    Trienode(char c){
        data=c;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};

class trie{
    public:
    Trienode* root;
    trie(){
        root=new Trienode('\0');
    }
    void recurseinsert(string s,Trienode* root){
        if(s.length()==0){
            root->isterminal=true;
            return;
        }
        int index=s[0]-'A';
        Trienode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            child=new Trienode(s[0]);
            root->children[index]=child;
        }
        recurseinsert(s.substr(1),child);
    }
    void insertion(string s){
        recurseinsert(s,root);
    }

    bool searching(string s){
        return searchtrie(s,root);
    }

    bool searchtrie(string s,Trienode* root){
        if(s.length()==0){
            return root->isterminal;
        }
        int index=s[0]-'A';
        Trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            return false;
        }
        return searchtrie(s.substr(1),child);
    }

};
int main(){
    trie* tr=new trie();

    tr->insertion("HELLO");
    tr->insertion("YUPPY");
    tr->insertion("CATS");
    tr->insertion("DOGS");
    cout<<tr->searching("DOGS");
    return 0;
}