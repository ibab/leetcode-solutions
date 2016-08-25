#include <iostream>
#include <array>
#include <random>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    Solution(ListNode* head) : head_(head), gen_(dev_()) {}

    // Implementation of reservoir sampling
    int getRandom() {
        std::uniform_real_distribution<double> dist(0, 1);
        if (!head_->next) {
            return head_->val;
        }
        ListNode* selected = head_;
        ListNode* curr = head_->next;
        for (int i = 2; curr; i++) {
            if (dist(gen_) < 1. / i) {
                selected = curr;
            }
            curr = curr->next;
        }
        return selected->val;
    }
private:
    std::random_device dev_;
    std::mt19937 gen_;
    ListNode* head_;
};

int main() {
    auto* a = new ListNode(0);
    a->next = new ListNode(1);
    a->next->next = new ListNode(2);
    a->next->next->next = new ListNode(3);
    a->next->next->next->next = new ListNode(4);
    Solution solution(a);
    std::array<int, 5> table;
    for (int i = 0; i < 1000000; i++) {
        table[solution.getRandom()]++;
    }
    for (int x: table) {
        std::cout << x << std::endl;
    }
    return 0;
}
