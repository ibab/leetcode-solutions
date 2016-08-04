// Problem 23 - Merge k Sorted Lists
//
// Merge k sorted linked lists and return it as one sorted list. Analyze and
// describe its complexity.

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// BEGIN
class Solution {
public:
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        ListNode* out = nullptr;
        ListNode* curr = nullptr;
        // Check for empty inputs
        if (!a) {
            return b;
        }
        if (!b) {
            return a;
        }
        // Initialize output
        if (a->val < b->val) {
            out = a;
            curr = a;
            a = a->next;
        } else {
            out = b;
            curr = b;
            b = b->next;
        }
        // Merge lists
        while (a && b) {
            if (a->val < b->val) {
                curr->next = a;
                curr = a;
                a = a->next;
            } else {
                curr->next = b;
                curr = b;
                b = b->next;
            }
        }
        // Append rest if the other list runs out
        if (a) {
            curr->next = a;
        } else if (b) {
            curr->next = b;
        }
        return out;
    }

    // Helper for recursion
    std::vector<ListNode*> mergeKListsHelper(std::vector<ListNode*>& lists) {
        if (lists.size() <= 1) {
            return lists;
        }
        int pairs = lists.size() / 2;
        int extra = lists.size() % 2;
        std::vector<ListNode*> tmp(pairs + extra, nullptr);
        for (int i = 0; i < pairs; i++) {
            tmp[i] = merge2Lists(lists[2 * i], lists[2 * i + 1]);
        }
        if (extra) {
            tmp[pairs] = lists[lists.size() - 1];
        }
        return mergeKListsHelper(tmp);
    }

    // The idea is to merge the input lists in a pairwise fashion.
    // This reduces the number of inputs from k to k / 2 at the next merging
    // level, where k is the initial number of lists.
    // This means that there are O(log k) merging levels.
    // At each level, we need to traverse O(n) elements to perform the merging
    // (in the worst case, we look at each element exactly once).
    // This results in a total O(n log k) time complexity.
    // This recursive solution could also be turned into an iterative one.
    // Because this solution destroys its inputs, a lot of work can be saved if
    // two lists have different lengths. This makes the solution FAST (it beat
    // 98.24% of the other solutions when I submitted it).
    //
    // An alternative solution can be achieved with the use of a priority queue.
    // Here, a priority queue is filled with the head of each list.
    // Because the heads are the smallest element of their list, the smallest
    // head is the smallest element overall.
    // This means we can retrieve the smallest element in the priority queue
    // and refill it with its successor (curr->next) if it exists.
    // We repeat this until we run out of elements.
    // Because the size of the priority queue constantly stays below k,
    // insertion has a time complexity of O(log k) (e.g. when using a priority
    // heap). Each element needs to be inserted, so we end up with a total time
    // complexity of O(n log k).
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() > 0) {
            return mergeKListsHelper(lists)[0];
        } else {
            return nullptr;
        }
    }
};
// END

std::string showList(ListNode* input) {
    if (!input) {
        return "[]";
    }
    std::stringstream ss;
    ss << "[";
    while (input->next) {
        ss << input->val << ", ";
        input = input->next;
    }
    ss << input->val << "]";
    return ss.str();
}

int main() {

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(5);
    ListNode* b = new ListNode(3);
    b->next = new ListNode(7);
    b->next->next = new ListNode(8);
    ListNode* c = new ListNode(4);
    c->next = new ListNode(6);

    std::vector<ListNode*> input = {a, b, c};

    Solution solution;
    ListNode* out = solution.mergeKLists(input);

    std::cout << "Output: " << showList(out) << std::endl;
    return 0;
}
