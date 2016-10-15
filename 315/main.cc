class Solution {
public:
    struct Node {
        int idx;
        int count;
        int answer;
        int val;
        Node* left;
        Node* right;
        Node(int idx_) : idx(idx_), count(0), left(nullptr), right(nullptr) {}
        ~Node() {
            if (left) {
                delete left;
            }
            if (right) {
                delete right;
            }
        }
    };
    
    int insert(Node* root, int idx, int answer) {
        if (idx > root->idx) {
            root->count++;
            if (!root->right) {
                root->right = new Node(idx);
                return answer;
            } else {
                return insert(root->right, idx, answer);
            }
        } else {
            int new_answer = answer + root->count + 1;
            if (!root->left) {
                root->left = new Node(idx);
                return new_answer;
            } else {
                return insert(root->left, idx, new_answer);
            }
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return std::vector<int>();
        }
        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); i++) {
            data.emplace_back(nums[i], i);
        }
        auto func = [](std::pair<int, int> a, std::pair<int, int> b) {
            if (a.first == b.first) {
                // Make sure that equal values never get in the way.
                return a.second < b.second;
            } else {
                // Sort by value.
                return a.first < b.first;
            }
        };
        sort(data.begin(), data.end(), func);
        Node* tree = new Node(data[0].second);
        std::vector<int> counts(nums.size());
        counts[data[0].second] = 0;
        for (int i = 1; i < data.size(); i++) {
            counts[data[i].second] = insert(tree, data[i].second, 0);
        }
        delete tree;
        return counts;
    }
};
