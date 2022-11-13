#include <bits/stdc++.h> 
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
class Trie{

    public:
    trienode* tr;
    Trie(){
        tr=new trienode('\0');
        // Write your code here.
    }
    void insertintrie(trienode* root,string s){
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
        insertintrie(root,s.substr(1));
    }
    void insert(string &word){
        insertintrie(tr,word);
    }
    int countword(trienode* root,string s){
        if(s.length()==0){
            return root->cw;
        }
        int index=s[0]-'a';
        if(root->children[index]!=NULL){
            root=root->children[index];
        }else return 0;
        return countword(root,s.substr(1));
    }
    int countWordsEqualTo(string &word){
        return countword(tr,word);
    }
    int countWordsStart(trienode* root,string s){
        if(s.length()==0){
            return root->cp;
        }
        int index=s[0]-'a';
        if(root->children[index]!=NULL){
            root=root->children[index];
        }else return 0;
        return countWordsStart(root,s.substr(1));
    }
    int countWordsStartingWith(string &word){
        return countWordsStart(tr,word);
    }
    void erasetrie(trienode* root,string s){
        if(s.length()==0){
            root->cw--;
            return;
        }
        int index=s[0]-'a';
        root=root->children[index];
        root->cp--;
        erasetrie(root,s.substr(1));
    }
    void erase(string &word){
        return erasetrie(tr,word);
    }
};
