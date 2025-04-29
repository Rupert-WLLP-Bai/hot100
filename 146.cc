#include "stdcc.h"
#include <unordered_map>
#include <utility>

class LRUCache {
  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        m.reserve(capacity);
    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        // 找到结果 移动cache
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second; // 返回迭代器指向的pair的value
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // 修改值
            m[key]->second = value;
            // 移动结点到最前
            cache.splice(cache.begin(), cache, m[key]);
        } else {
            if (m.size() == capacity) {
                // 如果满了
                // 找最后的节点
                const auto& rm = cache.back();
                // 在m中移除这个key
                m.erase(rm.first);
                // 移除cache最后
                cache.pop_back();
            }
            // 添加键值对到链表最前
            auto kv = make_pair(key, value);
            cache.emplace_front(kv);
            // 缓存添加 key -> cache开头的迭代器
            m.insert({key, cache.begin()});
        }
    }

  private:
    int capacity;
    list<pair<int, int>> cache; // 存储键值对, 最近使用的在最前
    unordered_map<int, list<pair<int, int>>::iterator> m; // key -> list迭代器
};