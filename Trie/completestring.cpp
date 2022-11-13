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
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
bool compare(string a,string b){
    if(a.length()==b.length()) return a<b;
    else return a.length()<b.length();
}
void insert(trienode* root,string s){
    if(s.length()==0){
        root->cp++;
        return;
    }
    int index=s[0]-'a';
    if(root->children[index]!=NULL){
        root=root->children[index];
    }else{
        root->children[index]=new trienode(s[0]);
        root=root->children[index];
    }
    insert(root,s.substr(1));
}
int main(){
    trienode* tr=new trienode('\0');
    string mx="";
    bool flag=true;
    // insert(tr,"n","n",mx,0,flag);
    // insert(tr,"ni","ni",mx,0,flag);
    // insert(tr,"nin","nin",mx,0,flag);
    // insert(tr,"ninj","ninj",mx,0,flag);
    // // insert(tr,"ninja","ninja",mx,0,flag);
    // insert(tr,"ninga","ninga",mx,0,flag);
    cout<<mx<<endl;
    return 0;
}