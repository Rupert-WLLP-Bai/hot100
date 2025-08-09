#include "stdcc.h"

class Solution {
  public:
    string validIPAddress(string queryIP) {
        if (isValidIP(queryIP)) {
            return getIPType(queryIP);
        }
        return "Neither";
    }

  private:
    bool isIPv4(const string& ip) {
        vector<string> parts;
        stringstream ss(ip);
        string part;
        while (getline(ss, part, '.')) {
            if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0') ||
                stoi(part) < 0 || stoi(part) > 255) {
                return false;
            }
            parts.push_back(part);
        }
        return parts.size() == 4;
    }

    bool isIPv6(const string& ip) {
        vector<string> parts;
        stringstream ss(ip);
        string part;
        while (getline(ss, part, ':')) {
            if (part.empty() || part.size() > 4 ||
                !all_of(part.begin(), part.end(), [](char c) { return isxdigit(c); })) {
                return false;
            }
            parts.push_back(part);
        }
        return parts.size() == 8;
    }

    bool isValidIP(const string& ip) { return isIPv4(ip) || isIPv6(ip); }

    string getIPType(const string& ip) {
        if (isIPv4(ip)) {
            return "IPv4";
        } else if (isIPv6(ip)) {
            return "IPv6";
        }
        return "Neither";
    }
};