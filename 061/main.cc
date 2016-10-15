class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // These need to be treated separately.
        if (!head || !head->next) {
            return head;
        }
        // Put the entire list on the stack.
        std::stack<ListNode*> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push(curr);
            curr = curr->next;
        }
        // Make sure that k is smaller than list size.
        k = k % stack.size();
        if (k == 0) {
            return head;
        }
        ListNode* last = stack.top();
        // Remove k elements from stack.
        for (int i = 0; i < k; i++) {
            stack.pop();
        }
        // Modify the list.
        ListNode* new_last = stack.top();
        ListNode* tmp = head;
        head = new_last->next;
        new_last->next = nullptr;
        last->next = tmp;
        return head;
    }
};
