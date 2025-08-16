#include "stdcc.h"
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (const auto& c: s){
            ++m1[c];
        }
        for(const auto& c: t){
            ++m2[c];
        }
        return m1 == m2;
    }
};