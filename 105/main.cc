#include <vector>
#include <stack>

using std::vector;
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Perform simultaneous traversals of the preorder and inorder vectors.
    // Use the fact that seeing/not seeing the current node as the next item
    // in the inorder traversal tells us whether there was a left subtree.
    // In the same way, use the fact that seeing/not seeing the parent node
    // next in the inorder traversal can tell us whether there was a right
    // subtree.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        stack<TreeNode*> stack;
        TreeNode* root = new TreeNode(preorder[0]);
        stack.push(root);
        int index = 0;
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = stack.top();
            if (node->val != inorder[index]) {
                // Recurse into left child.
                // This will cause us to always go left if possible, folowing
                // the preorder traversal.
                node->left = new TreeNode(preorder[i]);
                stack.push(node->left);
            } else {
                // If there is no left child, we backtrack as long as there is
                // no right subtree between the current node and its parent.
                while(!stack.empty() && stack.top()->val == inorder[index]) {
                    node = stack.top();
                    stack.pop();
                    index++;
                }
                // If we're not finished yet, we recurse into the right subtree.
                // This also correctly follows the preorder traversal.
                if (index < inorder.size()) {
                    node->right = new TreeNode(preorder[i]);
                    stack.push(node->right);
                }
            }
        }
        return root;
    }
};
