#include "stdcc.h"

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto p = list1;
        auto q = list2;
        auto dummy = new ListNode(-1);
        auto l = dummy;
        while (p && q) {
            if (p->val < q->val) {
                l->next = p;
                p = p->next;
                l = l->next;
            } else {
                l->next = q;
                q = q->next;
                l = l->next;
            }
        }
        while (!p && q) {
            l->next = q;
            q = q->next;
            l = l->next;
        }
        while (!q && p) {
            l->next = p;
            p = p->next;
            l = l->next;
        }
        return dummy->next;
    }
};