/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return recurse(root, 0);
    }

    int recurse(TreeNode* root, int num) {
        if (!root) {
            return 0;
        }
        int s = 10 * num + root->val;
        if (!root->right && !root->left) {
            return s;
        } else {
            return recurse(root->left, s) + recurse(root->right, s);
        }
    }
};
