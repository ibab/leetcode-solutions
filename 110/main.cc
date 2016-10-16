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
    bool isBalanced(TreeNode* root) {
        return recurse(root) != -1;
    }
    
    int recurse(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int a = recurse(root->left);
        if (a == -1) {
            return -1;
        }
        int b = recurse(root->right);
        if (b == -1) {
            return -1;
        }
        if (abs(a - b) > 1) {
            return -1;
        }
        return max(a, b) + 1;
    }
};
