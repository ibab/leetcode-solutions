
class Solution {
    enum Direction {
        LEFT,
        RIGHT,
    };

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root) {
            return recurse(root, RIGHT);
        }
        return 0;
    }

    int recurse(TreeNode* root, Direction dir) {
        if (!root->left && !root->right) {
            if (dir == LEFT) {
                return root->val;
            } else {
                return 0;
            }
        }

        int result = 0;
        if (root->left) {
            result += recurse(root->left, LEFT);
        }
        if (root->right) {
            result += recurse(root->right, RIGHT);
        }

        return result;
    }
};
