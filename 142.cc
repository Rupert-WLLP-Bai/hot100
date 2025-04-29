#include "stdcc.h"

class Solution {
  public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) return nullptr;
        auto slow = head;
        auto fast = head;
        auto meet = head;
        bool cycle = false;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                meet = slow;
                cycle = true;
                break;
            }
        }
        // q从相遇的位置开始, p从head开始
        if (cycle) {
            auto p = head;
            while (p != meet) {
                p = p->next;
                meet = meet->next;
            }
            return p;
        }
        return nullptr;
    }
};