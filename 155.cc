#include "stdcc.h"
#include <cstdint>

class MinStack {
  public:
    MinStack() { st.push(Node(INT32_MAX, INT32_MAX)); }

    // 每个节点自带一个最小值
    void push(int val) {
        if (val < st.top().min_val) {
            st.push(Node(val, val));
        } else {
            st.push(Node(val, st.top().min_val));
        }
    }

    void pop() { st.pop(); }

    int top() { return st.top().val; }

    int getMin() { return st.top().min_val; }

  private:
    struct Node {
        int val;
        int min_val;
        Node(int val, int min_val) : val(val), min_val(min_val) {}
    };
    stack<Node> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */