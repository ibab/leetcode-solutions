class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto iter = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), iter, nums.end());
        int median = *iter;

        // Maps indices from wiggly space into real values.
        auto A = [&nums](int i) -> int& {
            if (i < nums.size() / 2) {
                return nums[2 * i + 1];
            } else {
                return nums[2 * (i - nums.size() / 2)];
            }
        };

        // Partition nums such that smaller elements come
        // after the median, and larger ones come before it,
        // but do it in wiggly space.
        int i = 0;
        int j = 0;
        int k = nums.size() - 1;
        while (j <= k) {
            if (A(j) > median) {
                swap(A(i), A(j));
                i++;
                j++;
            } else if (A(j) < median) {
                swap(A(j), A(k));
                k--;
            } else {
                j++;
            }
        }
    }
};
