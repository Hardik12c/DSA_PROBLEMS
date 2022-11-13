#include <iostream>

using namespace std;
class trienode{
    public:
    char data;
    trienode* children[26];
    int cp;
    int cw;
    trienode(char data){
        this->data=data;
        cp=0;
        cw=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
void insert(trienode* root,string s){
    if(s.length()==0){
        root->cw++;
        return;
    }
    int index=s[0]-'a';
    if(root->children[index]!=NULL){
        root=root->children[index];
        root->cp++;
    }else{
        root->children[index]=new trienode(s[0]);
        root=root->children[index];
        root->cp++;
    }
    insert(root,s.substr(1));
}
int countwordequalto(trienode* root,string s){
    if(s.length()==0){
        return root->cw;
    }
    int index=s[0]-'a';
    if(root->children[index]!=NULL){
        root=root->children[index];
    }else return 0;
    return countwordequalto(root,s.substr(1));
}
int countWordsStartingWith(trienode* root,string s){
    if(s.length()==0){
        return root->cp;
    }
    int index=s[0]-'a';
    if(root->children[index]!=NULL){
        root=root->children[index];
    }else return 0;
    return countWordsStartingWith(root,s.substr(1));
}
void erase(trienode* root,string s){
    if(s.length()==0){
        root->cw--;
        return;
    }
    int index=s[0]-'a';
    root=root->children[index];
    root->cp--;
    erase(root,s.substr(1));
}
int main(){
    trienode* tr=new trienode('\0');
    insert(tr,"dogs");
    insert(tr,"dogs");
    insert(tr,"dogs");
    insert(tr,"dog");
    cout<<countwordequalto(tr,"dogs")<<endl;
    cout<<countWordsStartingWith(tr,"dog")<<endl;
    erase(tr,"dogs");
    cout<<countwordequalto(tr,"dogs")<<endl;
    cout<<countWordsStartingWith(tr,"dog")<<endl;
    return 0;
}