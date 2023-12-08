class Solution {
public:
    void preorder(TreeNode* node,string &s){
        if(!node){
            if(s[s.length()-1]!='(' && s[s.length()-1]!=')'){
              s+="()";
            }
            return;
        }
        s.push_back('(');
        if(node->val<=9 && node->val>=0){
          s+=node->val+'0';
        }else{
          s+=to_string(node->val);
        }
        if(!node->left && !node->right){
            s.push_back(')');
            return;
        }

        preorder(node->left,s);

        preorder(node->right,s);
        s.push_back(')');
    }
    string tree2str(TreeNode* root) {
        string s="";
        preorder(root,s);
        return s.substr(1,s.length()-2);
    }
};