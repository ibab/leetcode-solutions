class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int t = target - numbers[i];
            int left = i + 1;
            int right = numbers.size() - 1;
            while (left != right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] >= t) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (numbers[left] == t) {
                return {i + 1, left + 1};
            }
        }
        return {};
    }
};
