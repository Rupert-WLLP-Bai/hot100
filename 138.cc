#include "stdcc.h"
#include <unordered_map>

class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        auto m = unordered_map<Node*, Node*>(); // 原节点, 新节点

        auto p = head;
        // 构建映射关系
        while (p) {
            m[p] = new Node(p->val);
            p = p->next;
        }

        // 添加next指针和random指针
        p = head;
        while (p) {
            auto node = m[p];
            node->next = m[p->next];
            node->random = m[p->random];
            p = p->next;
        }

        return m[head]; // 返回head
    }
};