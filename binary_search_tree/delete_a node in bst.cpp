class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            TreeNode* ans=createnode(root);
            return ans;
        }
        TreeNode* temp=root;
        while(root!=NULL){
            if(key<root->val && root->left){
                if(root->left->val==key){
                    root->left=createnode(root->left);
                    break;
                }
                root=root->left;
            }else if(key>root->val && root->right){
                if(root->right->val==key){
                    root->right=createnode(root->right);
                    break;
                }
                root=root->right;
            }else{
                break;
            }
        }
        return temp;
    }
        TreeNode* createnode(TreeNode* root){
            if(root->left==NULL) return root->right;
            else if(root->right==NULL) return root->left;
            TreeNode* leftc=root->left;
            TreeNode* rightc=root->right;
            TreeNode* extright=extremeright(root->left);
            extright->right=rightc;
            return leftc;
        }
        TreeNode* extremeright(TreeNode* rig){
            if(rig->right==NULL){
                return rig;
            }
            return extremeright(rig->right);
        }
};