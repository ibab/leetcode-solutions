class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        results = vector<vector<int>>();
        vector<int> nums;
        nums.reserve(n);
        recurse(nums, n, k, 0);
        return results;
    }

    void recurse(vector<int>& nums, int n, int k, int s) {
        if (nums.size() == k) {
            results.push_back(nums);
            return;
        }
        int rest = k - nums.size();
        for (int i = s; i <= n - rest; i++) {
            nums.push_back(i + 1);
            recurse(nums, n, k, i + 1);
            nums.pop_back();
        }
    }


private:
    vector<vector<int>> results;
};
