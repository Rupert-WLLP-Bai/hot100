#include "stdcc.h"
#include <cctype>
#include <cstddef>
#include <stack>
#include <string>

class Solution {
public:
    string decodeString(string s) {
        stack<int> cnts;
        stack<string> res_st;
        string res;
        size_t i = 0;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    ++i;
                }
                cnts.push(count); // 将数字压入栈
            } else if (s[i] == '[') {
                res_st.push(res); // 当前构造结果入栈
                res = "";         // 开始构造新的 res
                ++i;
            } else if (s[i] == ']') {
                int count = cnts.top(); cnts.pop();
                string tmp = res_st.top(); res_st.pop();
                // 反复拼接 count 次
                while (count--) {
                    tmp += res;
                }
                res = tmp; // 替换为解码后的结果
                ++i;
            } else {
                res += s[i];
                ++i;
            }
        }

        return res;
    }
};
