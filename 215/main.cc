#include <vector>
#include <iostream>
#include <queue>

using std::vector;
using std::priority_queue;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 1; i < k; i++) {
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> data{5, 2, 4, 2, 1, 6, 3, 2};
    std::cout << Solution().findKthLargest(data, 2) << std::endl;
    return 0;
}
