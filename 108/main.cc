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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        nums_ = nums;
        return recurse(0, nums.size() - 1);
    }
    TreeNode* recurse(int start, int end) {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return new TreeNode(nums_[start]);
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums_[mid]);
        node->left = recurse(start, mid - 1);
        node->right = recurse(mid + 1, end);
        return node;
    }
private:
    vector<int> nums_;
};
