// LC 143 链表重排

#include "stdcc.h"

class Solution {
  public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        // 1. 找到中点
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2. 反转后半部分
        auto p = slow, q = p->next;
        p->next = nullptr; // 切断链表
        while (q) {
            auto tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        // 3. 合并两个链表
        auto l1 = head, l2 = p; // l2 是反转后的链表
        while (l2) {
            auto tmp1 = l1->next, tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
}; 