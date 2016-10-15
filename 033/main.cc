class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // First, find the beginning of the rotated array.
        while (left < right) {
            int mid = left + (right - left) / 2 + 1;
            if (nums[left] < nums[mid]) {
                // Go right.
                left = mid;
            } else if (nums[left] > nums[mid]) {
                // Go left.
                right = mid - 1;
            } else {
                // Supposedly, no duplicates exist.
                return -1;
            }
        }

        int beginning = (left + 1) % nums.size();

        // Now, find the index.
        left = 0;
        right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int val = nums[get(mid, beginning, nums.size())];
            if (val >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int val = nums[get(left, beginning, nums.size())];
        if (val != target) {
            return -1;
        }
        return get(left, beginning, nums.size());
    }

    int get(int idx, int beginning, int size) {
        return (idx + beginning) % size;
    }
};
