#include <unordered_map>
#include <vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:  
    unordered_map<int, Node*> mapping;
    Node* dfs(Node* curr) {
        if (!curr) {
            return NULL;
        }
        Node* newNode = new Node(curr->val);
        mapping[curr->val] = newNode;
        for (auto& nb : curr->neighbors) {
            if (mapping.find(nb->val) != mapping.end()) {
                newNode->neighbors.push_back(mapping[nb->val]);
                continue;
            }
            Node* neighbor = dfs(nb);
            newNode->neighbors.push_back(neighbor);
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        return dfs(node);
    }
};