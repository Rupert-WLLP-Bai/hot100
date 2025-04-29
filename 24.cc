#include "stdcc.h"

class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto prev = dummy; // 记录前面的节点
        while (head && head->next) {
            auto first = head;
            auto second = head->next;
            // 交换
            prev->next = second;
            first->next = second->next;
            second->next = first;
            // 移动
            prev = first;
            head = first->next;
        }
        return dummy->next;;
    }
};