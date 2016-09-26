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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result = recurse(root);
        std::reverse(result.begin(), result.end());
        return result;
    }
    vector<int> recurse(TreeNode* root) {
        if (!root) {
            return std::vector<int>();
        }
        std::vector<int> result_left = recurse(root->left);
        std::vector<int> result_right = recurse(root->right);

        int diff = result_left.size() - result_right.size();
        if (diff <= 0) {
            result_right.push_back(root->val);
            return result_right;
        } else {
            for (int i = diff;
                 i < result_left.size(); i++) {
                result_left[i] = result_right[i - diff];
            }
            result_left.push_back(root->val);
            return result_left;
        }
    }
};
