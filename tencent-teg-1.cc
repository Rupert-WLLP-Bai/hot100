#include "stdcc.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <sys/socket.h>

// 第一题

struct T {
    unsigned char a;
    int b;
};

int q1() {
    T t;
    memset(&t, 0xff, sizeof(T));
    t.a = 0;
    t.b = 0;
    unsigned char* p = &t.a + 1;
    printf("*p = %d\n", *p);
    return 0;
}

// 第二题

int q2() {
    uint32_t* p = (uint32_t*)(0x81000000);
    printf("p = %p\n", p);
    printf("p + 1 = %p\n", p + 1);
    return 0;
}

// 第三题
void fun(int* p) {
    p++;
    *p = 80;
}

int q3() {
    int a[4] = {20, 30, 40, 50};
    int* p = &a[1];
    printf("*p = %d\n", *p);
    fun(p);
    printf("*p = %d\n", *p);
    for (int i = 0; i < 4; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}

// 第四题
class RealServer {
  public:
    ~RealServer() { printf("RealServer destructed\n"); }
};

struct Service {
    vector<unique_ptr<RealServer>> servers;
};

int q4() {
    Service* service1 = new Service();
    service1->servers.push_back(make_unique<RealServer>());
    Service* service2 = new Service(std::move(*service1));
    cout << service1->servers.size() << endl;
    cout << service2->servers.size() << endl;
    delete service1;
    delete service2;
    return 0;
}

// 第五题
struct Key {
    int af;
    string id;

    Key(int af, string id) : af(af), id(id) {}
    Key(string id) : af(AF_INET), id(id) {}

    bool operator!=(const Key& other) const { return !(af == other.af && id == other.id); }

    bool operator==(const Key& other) const { return af == other.af && id == other.id; }

    bool operator<(const Key& other) const { return af < other.af && id < other.id; }
};
map<Key, string> m;
// 以上代码的问题在哪里?
// 答：Key 的比较操作符没有正确实现，< 操作符的正确实现先比较 af 字段，如果相等则比较 id 字段
// 这样可以确保 Key 的比较是基于 af 和 id 两个字段的组合，而不是单独比较。
// 即: return af < other.af || (af == other.af && id < other.id);

int main() {
    q1();
    q2();
    q3();
    q4();
    return 0;
}
