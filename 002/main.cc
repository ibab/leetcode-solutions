// Problem 2 - Add Two Numbers
//
// You are given two linked lists representing two non-negative numbers. The
// digits are stored in reverse order and each of their nodes contain a single
// digit. Add the two numbers and return it as a linked list.

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// BEGIN
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* out = nullptr;
        ListNode* curr = nullptr;

        while (l1 || l2 || carry != 0) {
            int num = 0;
            if (l1) {
                num += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num += l2->val;
                l2 = l2->next;
            }
            num += carry;
            carry = num / 10;
            ListNode* last = curr;
            curr = new ListNode(num % 10);
            if (!out) {
                out = curr;
            } else {
                last->next = curr;
            }
        }

        return out;
    }
};
// END

int main() {

    ListNode* a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);
    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);
    b->next->next->next = new ListNode(1);

    Solution solution;
    ListNode* out = solution.addTwoNumbers(a, b);
    std::cout << out->val << " " << out->next->val << " " << out->next->next->val << std::endl;

}
