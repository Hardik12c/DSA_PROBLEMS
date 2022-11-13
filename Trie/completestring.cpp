#include <bits/stdc++.h> 
class trienode{
    public:
    char data;
    trienode* children[26];
    bool isterminal;
    trienode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
void insert(trienode* root,string s){
    if(s.length()==0){
        root->isterminal=true;
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
bool search(trienode* root,string s){
    if(s.length()==0){
        return root->isterminal;
    }
    int index=s[0]-'a';
    if(root->children[index]!=NULL && root->children[index]->isterminal==true){
        root=root->children[index];
    }else return false;
    return search(root,s.substr(1));
}
bool compare(string a ,string b){
    if(a.length()==b.length()) return a>b;
    else return a.length()<b.length();
}
string completeString(int n, vector<string> &a){
    trienode* tr=new trienode('\0');
    for(int i=0;i<a.size();i++){
        insert(tr,a[i]);
    }
    string mx="";
    for(int i=0;i<a.size();i++){
        if(search(tr,a[i]) && compare(mx,a[i])){
            mx=a[i];
        }
    }
    if(mx=="") mx="None";
    return mx;
}