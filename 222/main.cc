
#include <iostream>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

enum Direction {
    LEFT,
    RIGHT
};


class Solution {
public:

    template <Direction D>
    int height(TreeNode* root) {
        int count = 0;
        while (root) {
            if (D == LEFT) {
                root = root->left;
            }
            if (D == RIGHT) {
                root = root->right;
            }
            count++;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = height<LEFT>(root);
        int right = height<RIGHT>(root);

        if (left == right) {
            return pow(2, left) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::cout << Solution().countNodes(root) << std::endl;
    return 0;
}
