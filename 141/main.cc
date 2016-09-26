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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            // First step of fast runner
            fast = fast->next;
            if (fast == slow) {
                return true;
            }
            if (!fast->next) {
                return false;
            }
            // Second step of fast runner
            fast = fast->next;
            if (fast == slow) {
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};
