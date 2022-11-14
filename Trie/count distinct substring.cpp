#include <bits/stdc++.h>
class trienode{
    public:
    char data;
    trienode* children[26];
    trienode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
void insert(trienode* root,string s,int &ans){
    if(s.length()==0){
        return;
    }
    int index=s[0]-'a';
    if(root->children[index]!=NULL){
        root=root->children[index];
    }else{
        ans++;
        root->children[index]=new trienode(s[0]);
        root=root->children[index];
    }
    insert(root,s.substr(1),ans);
}
int countDistinctSubstrings(string &s)
{
    trienode* root=new trienode('\0');
    int ans=0;
    for(int i=0;i<s.length();i++){
        insert(root,s.substr(i),ans);
    }
    return ans+1;
}