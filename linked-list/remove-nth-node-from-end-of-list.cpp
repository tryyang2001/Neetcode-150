#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> node;
        ListNode* curr = head;
        while (curr) {
            node.push_back(curr);
            curr = curr->next;
        }
        if (node.size() == 1) {
            return NULL;
        }
        int has_head = node.size() - n - 1;
        if (has_head >= 0) {
            //no node after the removed node
            if (n == 1) {
                node[node.size()-n-1]->next = NULL;
                delete node[node.size()-n];
            } else {
                node[node.size()-n] = NULL;
                node[node.size()-n-1]->next = node[node.size()-n+1]; //skip the removed node
            }
        } else {
            //remove head
            head = node[1];
            delete node[0];
        }
        return head;
    }
};