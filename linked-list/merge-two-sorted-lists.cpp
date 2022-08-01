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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return NULL;
        }
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->val = list1->val;
                list1 = list1->next;
            } else {
                curr->val = list2->val;
                list2 = list2->next;
            }
            curr->next = new ListNode();
            curr = curr->next;
        }
        ListNode* previous;
        while (list1) {
            curr->val = list1->val;
            list1 = list1->next;
            curr->next = new ListNode();
            previous = curr;
            curr = curr->next;
        }
        while (list2) {
            curr->val = list2->val;
            list2 = list2->next;
            curr->next = new ListNode();
            previous = curr;
            curr = curr->next;
        }
        previous->next = NULL;
        return head;
    }
};