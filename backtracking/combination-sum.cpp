#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, vector<int>& curr, int idx, int total, int target) {
        if (total == target) {
            ans.push_back(curr);
            return;
        }    
        if (total >= target || idx >= candidates.size()) {
            return;
        }
        curr.push_back(candidates[idx]);
        dfs(candidates, curr, idx, total + candidates[idx], target);
        curr.pop_back();
        dfs(candidates, curr, idx + 1, total, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //O(n*2^n)
        vector<int> curr;
        dfs(candidates, curr, 0, 0, target);
        return ans;
    }
};