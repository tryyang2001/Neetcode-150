#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    int kth;
    priority_queue<int,vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (auto& n : nums) {
            pq.push(n);
        }
        while (pq.size() > this->kth) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > this->kth) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */