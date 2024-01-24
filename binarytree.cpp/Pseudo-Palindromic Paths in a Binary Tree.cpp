class Solution {
public:
    int getcount(vector<int> count) {
        int one = 1;
        for (int i = 0; i < count.size(); i++) {
            if (count[i]%2!=0 && one > 0) {
                one--;
            } else if (count[i] % 2 != 0) {
                return 0;
            }
        }
        return 1;
    }
    int recurse(TreeNode* root, vector<int> count) {
        if (root == NULL) {
            return 0;
        }
        count[(root->val) - 1]++;
        if (!root->left && !root->right) {
            return getcount(count);
        }
        int left = recurse(root->left, count);
        int right = recurse(root->right, count);
        count[(root->val) - 1]--;
        return left + right;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> count(9, 0);
        return recurse(root, count);
    }
};