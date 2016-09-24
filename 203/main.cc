class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        ListNode *next = removeElements(head->next, val);
        if (head->val == val) {
            return next;
        } else {
            head->next = next;
            return head;
        }
    }
};

