#include <deque>
#include <vector>
#include <iostream>
#include <tuple>

template <typename T>
class MaxQueue {
public:
    MaxQueue() {}

    void push(const T& x) {
        int lives = 0;
        while (!queue_.empty() && std::get<0>(queue_.back()) < x) {
            lives += std::get<1>(queue_.back());
            lives++;
            queue_.pop_back();
        }
        queue_.emplace_back(x, lives);
    }

    void pop() {
        if (std::get<1>(queue_.front()) > 0) {
            std::get<1>(queue_.front())--;
        } else {
            queue_.pop_front();
        }
    }

    T max() {
        return std::get<0>(queue_.front());
    }
private:
    std::deque<std::tuple<T, int>> queue_;
};

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if (nums.empty()) {
            return std::vector<int>();
        }

        MaxQueue<int> queue;
        std::vector<int> output;
        for (int i = 0; i < k - 1; i++) {
            queue.push(nums[i]);
        }
        for (int i = k - 1; i < nums.size(); i++) {
            queue.push(nums[i]);
            output.push_back(queue.max());
            queue.pop();
        }
        return output;
    }
};

int main() {
    std::vector<int> input{5, 4, 3, 2, 1, 2, 3, 4, 5};
    auto out = Solution().maxSlidingWindow(input, 3);
    for (int i = 0; i < out.size(); i++) {
        std::cout << out[i] << std::endl;
    }

    return 0;
}
