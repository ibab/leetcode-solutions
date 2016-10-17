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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        return insert(head, head->next);
    }
    ListNode* insert(ListNode* x, ListNode* head) {
        if (!head) {
            x->next = nullptr;
            return x;
        }
        head = insert(head, head->next);
        if (x->val <= head->val) {
            x->next = head;
            return x;
        }
        ListNode* out = head;
        ListNode* curr = head;
        head = head->next;
        while (head) {
            if (x && x->val < head->val) {
                curr->next = x;
                curr = curr->next;
                curr->next = head;
                return out;
            }
            curr->next = head;
            curr = curr->next;
            head = head->next;
        }
        if (x) {
            curr->next = x;
            curr = curr->next;
            curr->next = nullptr;
        }
        return out;
    }
};
