#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    // Iterative solution that explicitly manages a stack.
    // While there are elements on the stack, try to fit each of the candidates numbers
    // into the target value and push them onto the stack if that's possible,
    // together with the history of all previously used numbers.
    // In order to remove duplicate histories, we impose an ordering on the
    // solution by requiring each new candidate to be smaller or equal to the
    // last one in the history.
    // This also somewhat prunes the evaluation tree.
    // If we manage to hit the target value precisely, we store the current
    // history as part of the solution.
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::stack<std::tuple<std::vector<int>, int>> stack;
        stack.push(std::make_tuple(std::vector<int>(), target));
        std::vector<std::vector<int>> results;
        while(!stack.empty()) {
            std::vector<int> history;
            int t;
            std::tie(history, t) = stack.top();
            stack.pop();
            for (int i = 0; i < candidates.size(); i++) {
                if (!history.empty() && history.back() < candidates[i]) {
                    continue;
                }
                if (candidates[i] < t) {
                    std::vector<int> copy = history;
                    copy.push_back(candidates[i]);
                    stack.push(std::make_tuple(copy, t - candidates[i]));
                } else if (candidates[i] == t) {
                    std::vector<int> copy = history;
                    copy.push_back(candidates[i]);
                    results.push_back(copy);
                }
            }
        }
        return results;
    }
};

int main() {
    Solution solution;
    std::vector<int> a{2, 3, 6, 7};
    auto out = solution.combinationSum(a, 7);
    for (int i = 0; i < out.size(); i++) {
        for (int j = 0; j < out[i].size(); j++) {
            std::cout << out[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
