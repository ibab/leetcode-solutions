
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }

        ListNode* out;
        ListNode* curr;
        if (l1->val < l2->val) {
            out = curr = l1;
            l1 = l1->next;
        } else {
            out = curr = l2;
            l2 = l2->next;
        }

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                curr = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
        }
        if (l1) {
            curr->next = l1;
        } else if (l2) {
            curr->next = l2;
        }
        return out;
    }
};
