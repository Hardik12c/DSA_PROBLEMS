class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        bool flag = false;
        while (!qu.empty()) {
            int n = qu.size();
            int num = qu.front()->val;
            for (int i = 0; i < n; i++) {
                TreeNode* node = qu.front();
                if ((flag && node->val % 2 != 0) ||
                    (!flag && node->val % 2 == 0) ||
                    (i > 0 && ((flag && node->val >= num) ||
                               (!flag && node->val <= num)))) {
                    return false;
                }
                qu.pop();
                num = node->val;
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
            flag = !flag;
        }
        return true;
    }
};