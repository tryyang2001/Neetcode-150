#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string, multiset<string>>& ticket_from, string curr, vector<string>& path) {
        while(!ticket_from[curr].empty()) {
            string next = *ticket_from[curr].begin();
            ticket_from[curr].erase(ticket_from[curr].begin());
            dfs(ticket_from, next, path);
        }
        path.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> path;
        unordered_map<string, multiset<string>> ticket_from;
        sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets) {
            ticket_from[ticket[0]].insert(ticket[1]);
        }
        dfs(ticket_from, "JFK", path);
        reverse(path.begin(), path.end());
        return path;
    }
};