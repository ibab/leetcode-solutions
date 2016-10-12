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
    // Move to the middle of the list while reversing everything up to that point.
    // Then, traverse the list in both directions simultaneously.
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* curr = head;
        int size = 1;
        while(curr->next) {
            curr = curr->next;
            size++;
        }

        int reverse = size / 2;
        int n = 1;
        ListNode* prev = head;
        curr = head->next;
        prev->next = nullptr;
        while (n < reverse) {
            ListNode* tmp = curr;
            curr = curr->next;
            tmp->next = prev;
            prev = tmp;
            n++;
        }

        if (size % 2 == 1) {
            curr = curr->next;
        }
        std::cout << curr->val << std::endl;
        while (curr) {
            if (curr->val != prev->val) {
                return false;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return true;
    }
};

