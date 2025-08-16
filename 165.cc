#include "stdcc.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // split the version strings by '.'
        vector<int> v1, v2;
        stringstream ss1(version1), ss2(version2);
        string token;
        while (getline(ss1, token, '.')) {
            v1.push_back(stoi(token)); // convert to integer
        }
        while (getline(ss2, token, '.')) {
            v2.push_back(stoi(token)); // convert to integer
        }
        // compare
        // make both vectors the same length by padding with zeros
        if (v1.size() < v2.size()) {
            v1.resize(v2.size(), 0);
        }
        else if (v2.size() < v1.size()) {
            v2.resize(v1.size(), 0);
        }
        // compare parts from left to right
        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] < v2[i]) {
                return -1;
            }
            else if (v1[i] > v2[i]) {
                return 1;
            }
        }
        return 0;      
    }
};