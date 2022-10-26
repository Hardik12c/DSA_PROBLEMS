class Solution {
  public:
    int countnodes(struct Node* root){
       if(root==NULL) return 0;
       
       return 1+countnodes(root->left)+countnodes(root->right);
    }
    // checking for cbt condition
    bool iscbt(struct Node* root,int i,int n){
        if(root==NULL) return true;
        if(i>=n) return false;
        
        return (iscbt(root->left,2*i+1,n) && iscbt(root->right,2*i+2,n));
        
    }
    bool isheap(struct Node* root){
        if(root==NULL) return true;
        if((root->left && root->left->data>root->data)|| (root->right && root->right->data>root->data)){
            return false;
        }
        
        return (isheap(root->left) && isheap(root->right));
        
    }
    bool isHeap(struct Node* tree) {
        if(iscbt(tree,0,countnodes(tree)) && isheap(tree)){
            return true;
        }
        return false;
    }
};