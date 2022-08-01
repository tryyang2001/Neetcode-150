#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[s.size() - (i+1)] != s[i]) {
                return false;
            }
        }
        return (s.size() > 0)? true : false;
    }
    
    void dfs(string s, int idx) {
        //base case
        if (idx == s.size()) {
            vector<string> new_curr(curr);
            ans.push_back(new_curr);
            return;
        }
        //find all possible partitions    
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(idx, i + 1);
            //cout << idx << ": " << part << endl;
            if (isPalindrome(part)) {
                curr.push_back(part);
                //cout << "next recursion" << endl;
                dfs(s, idx + 1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        dfs(s, 0);
        return ans;
    }
};