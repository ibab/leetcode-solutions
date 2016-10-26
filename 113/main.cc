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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) {
            return {};
        }
        path.clear();
        recurse(root, 0, sum);
        return results;
    }

    void recurse(TreeNode* node, int val, int sum) {
        if (!node->left && !node->right) {
            if (val + node->val == sum) {
                path.push_back(node->val);
                results.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(node->val);
        if (node->left) {
            recurse(node->left, val + node->val, sum);
        }
        if (node->right) {
            recurse(node->right, val + node->val, sum);
        }
        path.pop_back();
    }

private:
    vector<vector<int>> results;
    vector<int> path;
};
