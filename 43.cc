#include "stdcc.h"

class Solution {
  public:
    string multiply(string num1, string num2) {
        // 模拟竖式
        vector<int> res(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1]; // 当前位的乘积加上原来的值
                res[i + j + 1] = sum % 10;      // 尾数
                res[i + j] += sum / 10;         // 进位
            }
        }
        // 去除前导零
        string result;
        for (int num : res) {
            if (!(result.empty() && num == 0)) {
                result.push_back(num + '0');
            }
        }
        return result.empty() ? "0" : result;
    }
};