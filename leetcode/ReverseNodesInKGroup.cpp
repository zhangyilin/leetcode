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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* new_head = head;
        for (int i=0; i<k; ++i){
            if (new_head == NULL)   return head;
            new_head = new_head->next;
        }
        ListNode* grow = new_head;
        ListNode* current = head;
        for (int i=0; i<k; ++i){
            ListNode* next = current->next;
            current->next = grow;
            grow = current;
            current = next;
        }
        head->next = reverseKGroup(new_head, k);
        return grow;
    }
};
