#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& course_req, int idx, vector<bool>& visited) { 
        if (course_req[idx].size() == 0) {
            return true;
        }
        if (visited[idx]) {
            return false;
        }
        visited[idx] = 1;
        for (auto& req : course_req[idx]) {
            if (!dfs(course_req, req, visited)) {
                return false;
            }
        }
        course_req[idx].clear();
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, 0); //0 means not explored yet, 1 means cannot complete course, 2 means can complete
        vector<vector<int>> course_req(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            course_req[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(course_req, i, visited)) {
                return false;
            }
        }
        return true;
    }
};