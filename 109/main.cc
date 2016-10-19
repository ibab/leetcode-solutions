/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    tuple<ListNode*, ListNode*, ListNode*> split(ListNode* head) {
        if (!head) {
            return make_tuple(nullptr, nullptr, nullptr);
        }
        if (!head->next) {
            return make_tuple(nullptr, head, nullptr);
        }
        ListNode* last = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next) {
            fast = fast->next;
            last = slow;
            slow = slow->next;
            if (!fast->next) {
                break;
            }
            fast = fast->next;
        }
        if (slow == head) {
            head = nullptr;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        last->next = nullptr;
        return make_tuple(head, slow, right);
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode* left;
        ListNode* mid;
        ListNode* right;
        tie(left, mid, right) = split(head);
        TreeNode* result = new TreeNode(mid->val);
        result->left = sortedListToBST(left);
        result->right = sortedListToBST(right);
        return result;
    }
};
