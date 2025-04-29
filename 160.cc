#include "stdcc.h"
#include <unordered_set>

class Solution {
  public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> m;
        auto p = headA;
        auto q = headB;
        while (p) {
            m.insert(p);
            p = p->next;
        }
        while (q) {
            if (m.find(q) != m.end()) {
                return q;
            }
            q = q->next;
        }
        return nullptr;
    }
};