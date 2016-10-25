class Solution {
public:
    int findMin(const vector<int>& nums) {
        return recurse(nums, 0, nums.size() - 1);
    }

    int recurse(const vector<int>& nums, int start, int end) {
        cout << start << " " << end << endl;
        if (start == end) {
            return nums[start];
        }
        int mid = start + (end - start) / 2;
        int left = nums[start];
        int right = nums[end];
        int middle = nums[mid];

        if (left == middle || right == middle) {
            return min(recurse(nums, start, mid), recurse(nums, mid + 1, end));
        } else if (left > middle) {
            return recurse(nums, start, mid);
        } else if (right < middle) {
            return recurse(nums, mid + 1, end);
        } else {
            return recurse(nums, start, mid);
        }
    }
};
