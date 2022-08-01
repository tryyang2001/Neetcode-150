#include <unordered_map>
#include <vector>
#include <math.h>
using namespace std;
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> point_map;
    vector<vector<int>> points;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        point_map[point[0]][point[1]]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int count = 0;
        for (auto& pt : points) {
            if (abs(pt[0] - x) != abs(pt[1] - y) || pt[0] == x || pt[1] == y) {
                continue;
            }
            count += point_map[x][pt[1]] * point_map[pt[0]][y];
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */