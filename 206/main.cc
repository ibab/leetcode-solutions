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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        if (!head->next) {
            return head;
        }

        ListNode* next = head->next;
        ListNode* result = reverseList(next);
        next->next = head;
        head->next = nullptr;
        return result;
    }
};
