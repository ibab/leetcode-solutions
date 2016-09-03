
class NumArray {
public:
    NumArray(vector<int> &nums) {
        cumsum_ = std::vector<int>(nums.size() + 1, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cumsum_[i] = sum;
            sum += nums[i];
        }
        cumsum_[nums.size()] = sum;
    }

    int sumRange(int i, int j) {
        return cumsum_[j + 1] - cumsum_[i];
    }
private:
    vector<int> cumsum_;
};


