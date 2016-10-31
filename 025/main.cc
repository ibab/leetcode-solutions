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

    pair<ListNode*, ListNode*> reverseK(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* last = nullptr;
        for (int i = 0; i < k; i++) {
            ListNode* tmp = curr->next;
            curr->next = last;
            last = curr;
            curr = tmp;
        }
        return {last, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* result = new ListNode(0);
        ListNode* helper = result;
        ListNode* curr = head;
        while (head) {
            curr = head;
            int okay = true;
            for (int i = 0; i < k; i++) {
                if (!curr) {
                    okay = false;
                    helper->next = head;
                    break;
                }
                curr = curr->next;
            }
            if (!okay) {
                break;
            }

            ListNode* group_head;
            ListNode* group_tail;
            tie(group_head, group_tail) = reverseK(head, k);

            helper->next = group_head;
            helper = group_tail;
            head = curr;
        }
        ListNode* out = result->next;
        delete result;
        return out;
    }
};
