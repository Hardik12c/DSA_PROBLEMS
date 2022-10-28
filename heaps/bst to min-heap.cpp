class Solution{
  public:
    void inorder(Node* root,vector<int> &arr){
        if(root==NULL) return;
        
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    void change(Node* root,vector<int> &arr,int &i){
        if(root==NULL|| i == arr.size()){
            return;
        }
        
        root->data=arr[i++];
        change(root->left,arr,i);
        change(root->right,arr,i);

    }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> arr;
        inorder(root,arr);
        
        int i=0;
        change(root,arr,i);
    }    
};