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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>();
        }
        queue<TreeNode*> q;
        q.push(root);
        deque<TreeNode*> next;
        vector<vector<int>> result(1, vector<int>());
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (result.size() % 2 == 1) {
                if (curr->left) {
                    next.push_front(curr->left);
                }
                if (curr->right) {
                    next.push_front(curr->right);
                }
            } else {
                if (curr->right) {
                    next.push_front(curr->right);
                }
                if (curr->left) {
                    next.push_front(curr->left);
                }
            }
            result.back().push_back(curr->val);

            if (q.empty() && !next.empty()) {
                for (auto& x: next) {
                    q.push(x);
                }
                next.clear();
                result.push_back(vector<int>());
            }

        }
        return result;
    }
};
