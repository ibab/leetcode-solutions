/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<RandomListNode*, RandomListNode*> copy;
        RandomListNode* result = new RandomListNode(head->label);
        result->random = head->random;
        copy[head] = result;
        copy[nullptr] = nullptr;
        RandomListNode* c1 = head;
        RandomListNode* c2 = result;
        while (c1->next) {
            c2->next = new RandomListNode(c1->next->label);
            c2->next->random = c1->next->random;
            copy[c1->next] = c2->next;
            c1 = c1->next;
            c2 = c2->next;
        }
        RandomListNode* c = result;
        while (c) {
            cout << c << " " << c->random << " " << copy[c->random] << endl;
            c->random = copy[c->random];
            c = c->next;
        }
        return result;
    }
};
