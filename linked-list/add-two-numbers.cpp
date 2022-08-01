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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* curr = head;
        ListNode* prev;
        while (l1 && l2) {
            curr->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            curr->next = new ListNode();
            if (!l1 && !l2) {
               prev = curr; 
            }        
            curr = curr->next;
        }
        ListNode* remaining = (l1)? l1 : (l2)? l2 : NULL;
        while (remaining) {
            curr->val = (remaining->val + carry) % 10;
            carry = (remaining->val + carry) / 10;         
            remaining = remaining->next;
            curr->next = new ListNode();
            if (!remaining) {
                prev = curr;
            }
            curr = curr->next;           
        }
        if (carry) {
            curr->val = carry;
        } else {
            prev->next = NULL;
        }
        return head;
    }
};