# HOT100 速通

> 文档地址: https://ll2puk16qy.feishu.cn/sheets/RlbjsvICvhPtqptYUCnclRdhnCh?from=from_copylink

1. 回溯类模板写法

```cpp
class Solution {
public:
    vector<vector<int>> res; // 结果集（可以是vector<string>、vector<vector<string>>等）
    vector<int> path;        // 当前路径（可以换成string、vector<string>等）

    void backtrack(参数...) {
        if (终止条件) {
            res.push_back(path); // 或做其他处理
            return;
        }

        for (int i = 起始位置; i < 终止位置; ++i) {
            if (剪枝条件) continue;

            做选择;
            backtrack(参数...);   // 递归进入下一层
            撤销选择;            // 回溯
        }
    }

    vector<vector<int>> 回溯函数入口(参数...) {
        初始化变量;
        backtrack(参数...);
        return res;
    }
};
```