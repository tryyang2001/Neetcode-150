/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*if (!head) {
            return false;
        }
        if (head->next == head) {
            return true;
        }
        unordered_set<ListNode*> node_set;
        while (head->next) {
            if (node_set.find(head) != node_set.end()) {
                return true;
            }
            node_set.insert(head);
            head = head->next;
        }
        return false;*/
        if (!head || !head->next) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        fast = head;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;        
    }
};