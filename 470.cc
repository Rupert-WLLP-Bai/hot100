// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand7();

class Solution {
public:
    int rand10() {
        // 拒绝采样法
        int num;
        do {
            num = (rand7() - 1) * 7 + rand7();  // [1, 49]
        } while (num > 40); // 拒绝大于40的数
        return (num - 1) % 10 + 1;  // [1, 10]
    }
};