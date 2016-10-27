class Solution {
public:
    int findMin(vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1);
    }

    int recurse(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }
        int mid = i + (j - i) / 2;
        if (nums[i] == nums[mid] && nums[j] == nums[mid]) {
            return min(recurse(nums, i, mid), recurse(nums, mid + 1, j));
        }
        if (nums[j] < nums[mid]) {
            return recurse(nums, mid + 1, j);
        }
        return recurse(nums, i, mid);
    }
};
