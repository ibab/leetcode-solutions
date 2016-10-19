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
    pair<ListNode*, ListNode*> split(ListNode* head) {
        if (!head) {
            return make_pair(nullptr, nullptr);
        }
        if (!head->next) {
            return make_pair(head, nullptr);
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next) {
            fast = fast->next;
            if (!fast->next) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return make_pair(head, fast);
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        if (!b) {
            return a;
        }
        if (!a) {
            return b;
        }
        ListNode* out;
        if (a->val <= b->val) {
            out = a;
            a = a->next;
        } else {
            out = b;
            b = b->next;
        }
        ListNode* curr = out;
        while (a && b) {
            if (a->val <= b->val) {
                curr->next = a;
                curr = curr->next;
                a = a->next;
            } else {
                curr->next = b;
                curr = curr->next;
                b = b->next;
            }
        }
        if (a) {
            curr->next = a;
        } else if (b) {
            curr->next = b;
        }
        return out;
    }

    ListNode* sortList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }
        ListNode* left;
        ListNode* right;
        tie(left, right) = split(head);
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};
