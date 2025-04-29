#include "stdcc.h"

class Solution {
  public:
    bool isPalindrome(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next; // 如果为奇数则跳过中间值
        // 当前slow为后半段的起点
        auto behind = reverseList(slow);
        auto front = head;
        // 遍历比较
        while (behind) {
            if (front->val != behind->val) return false;
            front = front->next;
            behind = behind->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};