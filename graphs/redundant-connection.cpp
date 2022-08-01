#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        int p = parent[node];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    
    bool unionNodes(vector<int>& parent, vector<int>& rank, int node1, int node2) {
        int p1 = findParent(parent, node1);
        int p2 = findParent(parent, node2);
        //if 2 nodes have common parent, then that edge is redundant
        if (p1 == p2) {
            return false;
        }
        //like union-find disjoint set, node with higher rank will be the parent
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(edges.size() + 1, 1);
        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            if (!unionNodes(parent, rank, node1, node2)) {
                return edge;
            }
        }
        return {};
    }
};