#include <stack>
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
    void reorderList(ListNode* head) {
        stack<ListNode*> temp;
        ListNode* curr = head;
        while (curr) {
            temp.push(curr);
            curr = curr->next;
        }
        curr = head;
        int size = temp.size();
        int count = 0;
        int i = 0;
        ListNode* next = curr->next;
        while (count <= size && !temp.empty()) {
            if (i % 2 == 0) {
                curr->next = temp.top();
                temp.pop();
                size--;
            } else {
                curr->next = next;
                next = next->next;
                count++;
            }
            i = 1 - i;
            curr = curr->next;
        }
        curr->next->next = NULL;
    }
};