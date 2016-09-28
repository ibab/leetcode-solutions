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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* out = head->next;
        ListNode* tmp = head->next->next;
        out->next = head;
        head->next = tmp;
        ListNode* curr = head;

        while (true) {
            if (!curr->next || !curr->next->next) {
                return out;
            }
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            ListNode* tmp = second->next;
            curr->next = second;
            second->next = first;
            first->next = tmp;

            curr = curr->next;
            curr = curr->next;
        }

        return out;
    }
};

int main() {
    return 0;
}
