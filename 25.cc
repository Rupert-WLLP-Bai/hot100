#include "stdcc.h"
#include <utility>

class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto prev = dummy;
        auto tail = dummy;
        while (head) {
            // 检查head之后是否有k个节点
            // 如果有则反转
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return dummy->next;
                }
            }
            auto next_start = tail->next; // 下一组的起始位置
            // 重新赋值 new_node为2->1 和 1->3
            // prev->1->2->3->4->5
            // 现在链表是: prev->1->3->4->5
            //               2->1
            // 需要变为: 2->1->3->4->5
            //       prev->3
            tie(head, tail) = reverseList(head, tail);
            // 把子链表重新接回原链表
            prev->next = head;
            tail->next = next_start;
            prev = tail;
            head = tail->next;
        }
        return dummy->next;
    }

  private:
    /**
     * @brief 反转链表
     *
     * @param head
     * @param tail
     * @return pair<ListNode*, ListNode*> 翻转之后的头尾节点
     */
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next; // 用尾节点的后一个节点当前置节点
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev; // 第一步执行的时候 将头结点接到后一组的开始位置
            prev = p;
            p = nex;
        }
        return {tail, head};
    }
};