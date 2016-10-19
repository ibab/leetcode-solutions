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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        unordered_set<TreeNode*> visited;
        stack<TreeNode*> s;
        vector<int> result;
        s.push(root);
        visited.insert(root);
        visited.insert(nullptr);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            if (visited.find(curr->left) == visited.end()) {
                s.push(curr->left);
                continue;
            }
            if (visited.find(curr->right) == visited.end()) {
                s.push(curr->right);
                continue;
            }
            result.push_back(curr->val);
            visited.insert(curr);
            s.pop();
        }
        return result;
    }
};
