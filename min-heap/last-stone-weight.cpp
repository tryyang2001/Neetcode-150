#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> sorted_stones;
        for (auto& n : stones) {
            sorted_stones.push(n);
        }
        while (sorted_stones.size() > 1) {
            int stone1 = sorted_stones.top();
            sorted_stones.pop();
            int stone2 = sorted_stones.top();
            sorted_stones.pop();
            if (stone1 == stone2) {
                continue;
            } else if (stone1 < stone2) {
                stone2 -= stone1;
                sorted_stones.push(stone2);
            } else {
                stone1 -= stone2;
                sorted_stones.push(stone1);
            }
            //cout << "Largest stone remaining: " << sorted_stones.top() << endl;
        }
        return (sorted_stones.size() == 1)? sorted_stones.top() : 0;
    }
};