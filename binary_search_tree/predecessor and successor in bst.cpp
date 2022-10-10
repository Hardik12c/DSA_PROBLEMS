void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp=root;
    while(root!=NULL){
        if(key<root->key){
            suc=root;
            root=root->left;
        }else {
            root=root->right;
        }
    }
    root=temp;
    while(root!=NULL){
        if(key<=root->key){
            root=root->left;
        }else{
            pre=root;
            root=root->right;
        }
    }
}