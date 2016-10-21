class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int deleted = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i] && i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                deleted++;
            } else {
                nums[i - deleted] = nums[i];
            }
        }
        return nums.size() - deleted;
    }
};
