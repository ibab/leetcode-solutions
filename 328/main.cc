struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }
        ListNode* out[2];
        ListNode* heads[2];
        out[0] = heads[0] = head;
        out[1] = heads[1] = head->next;
        head = head->next->next;
        int idx = 0;
        while (head) {
            out[idx]->next = head;
            out[idx] = head;
            idx ^= 1;
            head = head->next;
        }

        out[0]->next = heads[1];
        out[1]->next = nullptr;

        return heads[0];
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* out = Solution().oddEvenList(head);
}
