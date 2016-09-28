/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// This can be done by finding out the length of the list
// first, but I wanted to solve it recursively in one go.
class Solution {
public:

    std::pair<ListNode*, int> recurse(ListNode* head, int n) {
        if (!head) {
            return std::pair<ListNode*, int>(nullptr, 1);
        } else {
            ListNode* result;
            int distance;
            // Get next element and distance to end
            std::tie(result, distance) = recurse(head->next, n);
            if (distance == n) {
                // Remove this element from the list
                head = result;
            } else {
                // Don't remove this element
                head->next = result;
            }
            return std::pair<ListNode*, int>(head, distance + 1);
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return recurse(head, n).first;
    }
};
