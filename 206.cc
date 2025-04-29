#include "stdcc.h"

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        auto p = head;
        auto q = head->next;
        while (q) {
            auto tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        head->next = nullptr; // 尾结点
        return p;
    }

    ListNode* reverseList2(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};