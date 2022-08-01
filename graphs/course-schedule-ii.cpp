#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& course_req, int course, vector<int>& state, vector<int>& ans) {
        if (state[course]) {
            return;
        }
        state[course] = 1;
        for (auto& req : course_req[course]) {
            if (!state[req]) {
                dfs(course_req, req, state, ans);
            }
            if (state[req] == 1) {
                return;
            }
        }
        state[course] = 2;
        ans.push_back(course); //ans will be the topological sort order
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course_req(numCourses);
        for (auto& course : prerequisites) {
            course_req[course[0]].push_back(course[1]);
        }
        vector<int> state(numCourses, 0); //0 means not yet attempt, 1 means it forms a cycle, 2 means correctly visited and processed
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!state[i]) {
                dfs(course_req, i, state, ans);
            }
            if (state[i] == 1) {
                return {};
            }
        }
        return ans; 
    }
};