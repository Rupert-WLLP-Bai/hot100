#include "stdcc.h"
#include <stack>

class Solution {
  public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty()) return false; // 如果开头就是右括号
                if ((c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};