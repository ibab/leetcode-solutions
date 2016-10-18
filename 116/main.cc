/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        recurse(root, nullptr);
    }

    void recurse(TreeLinkNode* root, TreeLinkNode* next) {
        if (!root) {
            return;
        }
        root->next = next;
        if (next) {
            next = next->left;
        }
        recurse(root->right, next);
        recurse(root->left, root->right);
    }
};
