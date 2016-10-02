class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) {
            return nullptr;
        }
        stack<TreeNode*> stack;
        TreeNode* root = new TreeNode(postorder.back());
        stack.push(root);
        int index = inorder.size() - 1;
        for (int i = postorder.size() - 2; i >= 0; i--) {
            TreeNode* node = stack.top();
            if (node->val != inorder[index]) {
                // Recurse into right child.
                node->right = new TreeNode(postorder[i]);
                stack.push(node->right);
            } else {
                // If there is no right child, we backtrack as long as there is
                // no left subtree between the current node and its parent.
                while(!stack.empty() && stack.top()->val == inorder[index]) {
                    node = stack.top();
                    stack.pop();
                    index--;
                }
                // If we're not finished yet, we recurse into the left subtree.
                if (index < inorder.size()) {
                    node->left = new TreeNode(postorder[i]);
                    stack.push(node->left);
                }
            }
        }
        return root;
    }
};
