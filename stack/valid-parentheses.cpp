#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) {
            return false;
        }
        stack<char> paran_checker;
        for (auto& c : s) {
            switch (c) {
                case '{':
                case '[':
                case '(':
                    paran_checker.push(c);
                    break;
                case '}':
                    if (paran_checker.size() == 0 || paran_checker.top() != '{') {
                        return false;
                    }
                    paran_checker.pop();
                    break;
                case ']':
                    if (paran_checker.size() == 0 || paran_checker.top() != '[') {
                        return false;
                    }
                    paran_checker.pop();
                    break;
                case ')':
                    if (paran_checker.size() == 0 || paran_checker.top() != '(') {
                        return false;
                    }
                    paran_checker.pop();
                    break;
                default:
                    return false;
            }
        }
        if (paran_checker.size() > 0) {
            return false;
        }
        return true;
    }
};