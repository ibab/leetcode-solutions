/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* recurse(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        if (head->val == val) {
            // We are part of a run of equal values.
            return recurse(head->next, val);
        } else if (head->next && head->val == head->next->val) {
            // We are at the very beginning of a run of equal values.
            return recurse(head->next, head->val);
        }
        // We want to keep this value.
        head->next = recurse(head->next, head->val);
        return head;
    }

    /*
     * The tricky part in this problem is that it requires us to remove
     * the current value if either of two conditions are true:
     *  - The current and next element are equal
     *  - The current and last element are equal
     *  It's not enough to handle just one of these, as this will mean
     *  that we either leave the first or last element of the run intact.
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // A separate flag could be used instead of INT_MAX if necessary.
        return recurse(head, INT_MAX);
    }
};
