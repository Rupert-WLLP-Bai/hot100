#include "stdcc.h"
#include <cctype>
#include <cstddef>
#include <stack>
#include <string>

class Solution {
  public:
    // LeetCode 394 字符串解码
    string decodeString(string s) {
        // 左括号入栈，右括号出栈拼接
        stack<int> cnts;
        stack<string> res_st;
        string res;
        size_t i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                // 读出这个数
                size_t count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    ++i;
                }
            } else if (s[i] == '['){
                
            } else if (s[i] == ']'){

            } else {
                // 直接加入
                res += s[i];
                ++i;
            }
        }
        return res;
    }
};