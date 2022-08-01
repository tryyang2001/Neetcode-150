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
    ListNode* reverse(ListNode* curr, ListNode* prev) {
        ListNode* next = curr->next;
        curr->next = prev;
        if (!next) {
            return curr;
        }
        reverse(next, curr);
        return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        int count = 0;
        ListNode* curr = head;
        ListNode* new_head = head;
        bool first = true;
        ListNode* curr_prev = NULL;
        ListNode* curr_head;
        while (curr) {
            if (count == 0) {
                curr_head = curr;
            }
            count++;
            if (count == k) {
                if (first) {
                    new_head = curr; //to have the returned node
                    first = false;
                }
                ListNode* continue_node = curr->next; //to continue the loop if possible
                curr->next = NULL; //so that reverse function has breakpoint
                if (curr_prev) {
                    curr_prev->next = curr; //to connect previous last to curr first
                }
                curr_prev = reverse(curr_head, NULL); //update curr_prev to curr last
                curr = continue_node;
                count = 0;
                continue;
            }
            curr = curr->next;
        }
        if (count != 0) {
            curr_prev->next = curr_head;
        }
        curr = new_head;
        count = 0;
        return new_head;
    }
};