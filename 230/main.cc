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
    int kthSmallest(TreeNode* root, int& k) {

        if (root->left) {
            int x = kthSmallest(root->left, k);
            if (k <= 0) {
                return x;
            }
        }
        k--;
        if (k == 0) {
            return root->val;
        }
        if (root->right) {
            return kthSmallest(root->right, k);
        }
        return -1;
    }
};
