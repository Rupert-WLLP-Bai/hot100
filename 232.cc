#include "stdcc.h"
#include <stack>

// 思路: 一个栈用于入队，另一个栈用于出队
// 当出队栈为空时，将入队栈的元素全部转移到出队栈
// 这样可以保证出队顺序是先进先出
// 注意: 需要处理空栈的情况

class MyQueue {
  public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() { return s1.empty() && s2.empty(); }

  private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */