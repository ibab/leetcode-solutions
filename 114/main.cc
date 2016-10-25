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
    void flatten(TreeNode* root) {
        recurse(root);
    }

    TreeNode* recurse(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* left = recurse(root->left);
        TreeNode* right = recurse(root->right);
        if (left) {
            left->right = root->right;
            root->right = root->left;
        }
        root->left = nullptr;
        if (right) {
            return right;
        }
        if (left) {
            return left;
        }
        return root;
    }
};
