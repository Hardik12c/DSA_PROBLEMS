class BSTIterator {
public:
    TreeNode* main;
    stack<TreeNode*> k;
    TreeNode* temp;
    bool check=true;
    int i=0;
    BSTIterator(TreeNode* root,bool flag) {
        this->main=root;
        check=flag;
        pushall(main);
    }    
    int next() {
        TreeNode* m=k.top();
        k.pop();
        if(check){
            pushall(m->right);
        }else pushall(m->left);
        return m->val;
    }
private:
    void pushall(TreeNode* temp){
        while(temp!=NULL){
            k.push(temp);
            if(check) temp=temp->left;
            else temp=temp->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator inc(root,true);
        BSTIterator dec(root,false);
        int i =inc.next();
        int j=dec.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=inc.next();
            else   j=dec.next();
        }
        return false;
    }
};