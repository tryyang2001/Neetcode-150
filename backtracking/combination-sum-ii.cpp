#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> candidates, vector<int> curr, int idx, int total, int target) {
        if (total == target) {
            ans.push_back(curr);
            return;
        }
        if (total >= target || idx >= candidates.size()) {
            return;
        }
        curr.push_back(candidates[idx]);
        dfs(candidates, curr, idx + 1, total + candidates[idx], target);
        curr.pop_back();
        idx++;
        while (idx < candidates.size() && candidates[idx] == candidates[idx-1]){
            idx++;
        }
        dfs(candidates, curr, idx, total, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, curr, 0, 0, target);
        return ans;
    }
};