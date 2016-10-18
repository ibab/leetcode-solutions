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
    vector<int> inorderTraversal(TreeNode* root) {
        results = vector<int>();
        recurse(root);
        return results;
    }
    void recurse(TreeNode* root) {
        if (!root) {
            return;
        }
        recurse(root->left);
        results.push_back(root->val);
        recurse(root->right);
    }
private:
    vector<int> results;
};
