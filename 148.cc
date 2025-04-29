#include "stdcc.h"
#include <vector>

class Solution {
  public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        vector<pair<int, ListNode*>> vec;
        while (head) {
            vec.push_back(make_pair(head->val, head));
            head = head->next;
        }
        sort(vec.begin(), vec.end(), [](const auto& v1, const auto& v2) {
            return v1.first < v2.first;
        });
        auto dummy = new ListNode(-1);
        auto p = dummy;
        for (const auto& v : vec) {
            p->next = v.second;
            p->next->val = v.first;
            p = p->next;
        }
        p->next = nullptr;
        return dummy->next;
    }
};