#include <vector>
#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& ans, deque<string> paran_generator, int open_count, int close_count, int n) {
        if (open_count == close_count && open_count == n) {
            string valid_paran = "";
            while (paran_generator.size() != 0) {
                valid_paran += paran_generator.front();
                paran_generator.pop_front();
            }
            ans.push_back(valid_paran);
            return;
        }
        if (open_count < n) {
            paran_generator.push_back("(");
            backtrack(ans, paran_generator, open_count + 1, close_count, n);
            paran_generator.pop_back();
        }
        if (close_count < open_count) {
            paran_generator.push_back(")");
            backtrack(ans, paran_generator, open_count, close_count + 1, n);
            paran_generator.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        //backtrack stack
        vector<string> ans;
        deque<string> paran_generator;
        backtrack(ans, paran_generator, 0, 0, n);
        return ans;
    }
};