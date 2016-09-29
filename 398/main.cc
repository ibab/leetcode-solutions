
class Solution {
public:
    Solution(const vector<int>& nums) : nums_(nums) {
    }
    
    int pick(int target) {
        int reservoir = -1;
        int step = 1;
        for (int i = 0; i < nums_.size(); i++) {
            if (nums_[i] == target && (rand() % step++) == 0) {
                reservoir = i;
            }
        }
        return reservoir;
    }
private:
    std::vector<int> nums_;
};
