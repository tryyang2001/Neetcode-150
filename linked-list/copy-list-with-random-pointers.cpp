#include <unordered_map>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        //construct a new list
        unordered_map<Node*, Node*> mapping; //map original node to new node
        Node* curr = head;
        Node* new_head;
        while (curr) {
            mapping[curr] = new Node(0);
            curr = curr->next;
        }
        new_head = mapping[head];
        curr = new_head;
        int count = 0;
        while (head) {
            curr->val = head->val;
            curr->next = mapping[head->next];
            curr->random = mapping[head->random];
            head = head->next;
            curr = curr->next;
        }
        return new_head;
    }
};