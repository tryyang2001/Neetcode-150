#include <stack>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> stk; //first stores curr val, second stores 
    
public:
    MinStack() {

    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push({val, val});
        } else {
            int curr_min = stk.top().second;
            if (val < curr_min) {
                stk.push({val, val});
            } else {
                stk.push({val, curr_min});
            }
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        int curr_min = stk.top().second;
        return curr_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */