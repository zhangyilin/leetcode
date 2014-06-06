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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* second = head;
        for (int i=0; i<n; ++i){
            if (second == NULL) return head;
            second = second->next;
        }
        if (second == NULL){
            return head->next;
        }
        ListNode* first = head;
        while (second->next){
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};
