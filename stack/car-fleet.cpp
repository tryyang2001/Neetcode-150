#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars;
        for (int i = 0; i < position.size(); i++) {
            float time = (target - position[i]) / float(speed[i]);
            cars.push_back(make_pair(position[i], time));
        }
        sort(cars.begin(), cars.end());
        int cluster = 1;
        for (int i = position.size() - 1; i > 0; i--) {
            if (cars[i-1].second - cars[i].second <= 0) {
                cars[i-1].second = cars[i].second;
            } else {
                cluster++;
            }
        }
        return cluster;
    }
};