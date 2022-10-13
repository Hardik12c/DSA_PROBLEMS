class colls{
    public:
    int mini;
    int maxi;
    bool isbst;
    int maxsize;
};
colls solve(TreeNode<int>* root,int &size){
    if(root==NULL){
        return {INT_MAX,INT_MIN,true,0};
    }
    colls lefti=solve(root->left,size);
    colls righti=solve(root->right,size);
    colls check;
    check.mini=min(root->data,lefti.mini);
    check.maxi=max(root->data,righti.maxi);
    check.maxsize=lefti.maxsize+righti.maxsize+1;
    if(lefti.isbst&& righti.isbst && root->data>lefti.maxi && root->data<righti.mini){
        check.isbst=true;
    }else check.isbst=false;
    
    if(check.isbst) size=max(size,check.maxsize);
    return check;
}
int largestBST(TreeNode<int>* root) 
{
    int size=INT_MIN;
    solve(root,size);
    return size;
    
}
