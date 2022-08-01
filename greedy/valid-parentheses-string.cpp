#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left_paran;
        stack<int> star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left_paran.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if (!left_paran.empty()) {
                    left_paran.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }
        while (!left_paran.empty()) {
            if (!star.empty()) {
                if (star.top() > left_paran.top()) {
                    star.pop();
                    left_paran.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};