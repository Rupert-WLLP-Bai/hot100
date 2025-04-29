#include "stdcc.h"

class Solution {
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 分治法
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        ListNode head, *tail = &head, *a = l1, *b = l2;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head.next;
    }

    ListNode* merge(vector<ListNode*>& list, int l, int r) {
        if (l == r) return list[l];
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        return merge2Lists(merge(list, l, mid), merge(list, mid + 1, r));
    }
};