#include "stdcc.h"

class Trie {
  private:
    // 定义每个节点的数据结构
    struct TrieNode {
        bool isEnd;             // 表示是否是某个单词的结尾
        TrieNode* children[26]; // 指向26个小写字母的子节点

        TrieNode() : isEnd(false) {
            // 初始化所有子节点为空指针
            fill(begin(children), end(children), nullptr);
        }
    };

    TrieNode* root; // 根节点

  public:
    Trie() {
        root = new TrieNode(); // 初始化根节点
    }

    // 插入一个单词到Trie中
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a'; // 将字符映射到0-25之间
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode(); // 创建新节点
            }
            node = node->children[idx]; // 移动到下一个节点
        }
        node->isEnd = true; // 最后一个字符标记为单词结尾
    }

    // 查找一个完整单词是否存在于Trie中
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false; // 没有路径，返回false
            node = node->children[idx];
        }
        return node->isEnd; // 判断最后一个字符是否是单词结尾
    }

    // 判断是否存在某个前缀
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false; // 没有路径，返回false
            node = node->children[idx];
        }
        return true; // 只要路径走完，说明有该前缀
    }
};
