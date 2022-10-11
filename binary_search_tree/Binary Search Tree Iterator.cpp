class BSTIterator {
public:
    TreeNode* main;
    stack<TreeNode*> k;
    TreeNode* temp;
    int i=0;
    BSTIterator(TreeNode* root) {
        this->main=root;
        temp=main;
        while(temp!=NULL){
            k.push(temp);
            temp=temp->left;
        }
    }    
    int next() {
        TreeNode* m=k.top();
        k.pop();
        if(m->right){
            temp=m->right;
            while(temp!=NULL){
                k.push(temp);
                temp=temp->left;
            }
        }
        return m->val;
    }
    
    bool hasNext() {
        if(!k.empty()) return true;
        else return false;
    }
};