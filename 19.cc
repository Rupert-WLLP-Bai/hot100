#include "stdcc.h"

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if (!head->next) return nullptr;
        // 快慢指针
        // 先走n步
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto slow = dummy;
        auto fast = dummy;
        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        auto prev = slow;
        // 删除的节点是prev的下一个
        auto del = prev->next;
        prev->next = del->next;
        delete del;

        return dummy->next;
    }
};