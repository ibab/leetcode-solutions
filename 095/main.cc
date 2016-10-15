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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return std::vector<TreeNode*>();
        }
        map.clear();
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        if (map.find(pair<int, int>(start, end)) != map.end()) {
            return map[{start, end}];
        }
        if (start == end) {
            return {new TreeNode(start)};
        }
        vector<TreeNode*> results;
        for (int i = start; i <= end; i++) {
            auto smaller = generateTrees(start, i - 1);
            auto larger = generateTrees(i + 1, end);
            for (auto& s: smaller) {
                for (auto& l: larger) {
                    TreeNode* node = new TreeNode(i);
                    node->left = s;
                    node->right = l;
                    results.push_back(node);
                }
            }
        }
        map[{start, end}] = results;
        return results;
    }
private:
    std::map<pair<int, int>, vector<TreeNode*>> map;
};
