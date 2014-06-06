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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* first = head;
        if (first == NULL)   return head;
        ListNode* second = first->next;
        if (second == NULL)   return head;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
};
