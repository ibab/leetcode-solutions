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
    ListNode* partition(ListNode* head, int k) {
      ListNode* smaller = nullptr;
      ListNode* larger = nullptr;
      ListNode* result_left = nullptr;
      ListNode* result_right = nullptr;
      while(head) {
        if (head->val < k) {
          if (!smaller) {
            smaller = head;
            result_left = smaller;
          } else {
            smaller->next = head;
            smaller = smaller->next;
          }
        } else {
          if (!larger) {
            larger = head;
            result_right = head;
          } else {
            larger->next = head;
            larger = larger->next;
          }
        }
        head = head->next;
      }
      if (larger) {
        larger->next = nullptr;
      }
      if (smaller) {
        smaller->next = result_right;
      }
      return result_left ? result_left : result_right;
    }
};
