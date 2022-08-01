#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        if (max_heap.size() - min_heap.size() > 1) {
            //throw max from max_heap to min_heap
            min_heap.push(max_heap.top());
            max_heap.pop();
            return;
        }
        if (max_heap.size() && min_heap.size() && max_heap.top() > min_heap.top()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            if (min_heap.size() - max_heap.size() > 1) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            //even case
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        //odd case
        return (max_heap.size() > min_heap.size())? max_heap.top() : min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */