#include "stdcc.h"

class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next) {
            if (p->next->val == val) {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};