#include "stdcc.h"

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto l = dummy;
        int cnt = 0;
        while (l1 && l2) {
            auto sum = l1->val + l2->val + cnt;
            l->next = new ListNode(sum % 10);
            cnt = sum / 10;
            l = l->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        auto rest = l1 ? l1 : l2; // 剩余未处理完的链
        while (rest) {
            auto sum = rest->val + cnt;
            l->next = new ListNode(sum % 10);
            cnt = sum / 10;
            l = l->next;
            rest = rest->next;
        }
        // 如果最后还有进位就加上一位1
        if (cnt) {
            l->next = new ListNode(1);
        }
        return dummy->next;
    }
};