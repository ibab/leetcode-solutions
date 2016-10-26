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

    TreeLinkNode* findRight(TreeLinkNode* root) {
        while (root->next) {
            root = root->next;
            if (root->left) {
                return root->left;
            }
            if (root->right) {
                return root->right;
            }
        }
        return nullptr;
    }

    void recurse(TreeLinkNode* root, TreeLinkNode *extra) {
        if (!root) {
            return;
        }
        root->next = extra;
        recurse(root->right, findRight(root));
        if (root->right) {
            recurse(root->left, root->right);
        } else {
            recurse(root->left, findRight(root));
        }
    }
};
