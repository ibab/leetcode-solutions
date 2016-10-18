class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        if (target > nums.back()) {
            return nums.size();
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - mid) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
