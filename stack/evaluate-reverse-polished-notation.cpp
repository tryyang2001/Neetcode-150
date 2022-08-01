#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOperator(string c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> accumulator;
        for (auto& c : tokens) {
            if (!isOperator(c)) {
                accumulator.push(stoi(c));
            } else {
                int num1 = accumulator.top();
                accumulator.pop();
                int num2 = accumulator.top();
                accumulator.pop();
                if (c == "+") {
                    accumulator.push(num2 + num1);
                } else if (c == "-") {
                    accumulator.push(num2 - num1);
                } else if (c == "*") {
                    accumulator.push(num2 * num1);
                } else if (c == "/") {
                    accumulator.push(num2 / num1);
                } else {
                    return -1;
                }
            }
        }
        return accumulator.top();
    }
};