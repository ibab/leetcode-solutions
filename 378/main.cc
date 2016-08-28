#include <vector>
#include <queue>
#include <iostream>
#include <set>

using std::vector;
using std::tuple;
using std::get;
using std::make_tuple;
using std::tie;

class Solution {

public:
    // Simply perform a k-way merge of the n rows of the matrix
    // Runtime is O(k log n)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto compare = [](
            const tuple<int, int, int>& a,
            const tuple<int, int, int>& b) {
          return get<0>(a) > get<0>(b);  
        };
        std::priority_queue<
          tuple<int, int, int>,
          vector<tuple<int, int, int>>,
          decltype(compare)> queue(compare);

        for (int i = 0; i < matrix.size(); i++) {
            queue.push(make_tuple(matrix[i][0], i, 0));
        }

        int value;
        int i;
        int j;
        for (int l = 0; l < k; l++) {
            tie(value, i, j) = queue.top();
            queue.pop();

            if (j + 1 < matrix.size()) {
                queue.push(make_tuple(matrix[i][j + 1], i, j + 1));
            }
        }

        return matrix[i][j];
    }
};

int main() {
    vector<vector<int>> input = {{3,5,9,9,9},{5,8,13,13,16},{10,10,14,14,16},{15,18,20,24,26},{20,24,29,32,37}};
    std::cout << Solution().kthSmallest(input, 25) << std::endl;
    return 0;
}
