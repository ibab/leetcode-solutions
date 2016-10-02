class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return recurse(nums);
    }


    vector<vector<int>> recurse(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>(1, vector<int>());
        }
        int num = nums.back();
        nums.pop_back();
        int count = 1;
        while (!nums.empty() && nums.back() == num) {
            nums.pop_back();
            count++;
        }
        vector<vector<int>> solutions = subsetsWithDup(nums);
        std::cout << solutions.size() << std::endl;
        int n = solutions.size();
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= count; k++) {
                auto copy = solutions[i];
                for (int j = 0; j < k; j++) {
                    copy.push_back(num);
                }
                solutions.push_back(copy);
            }
        }
        return solutions;
    }
};
