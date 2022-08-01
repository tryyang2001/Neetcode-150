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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* previous = new ListNode(head->val);
        while (head->next) {
            ListNode* curr = new ListNode(head->next->val, previous);
            previous = curr;
            head = head->next;
        }
        return previous;
    }
};