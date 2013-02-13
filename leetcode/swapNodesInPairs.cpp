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
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (head == NULL || head->next ==NULL){
                return head;
            }
            ListNode * current = new ListNode(0);
            ListNode * next = head;
            ListNode * next_next = head->next;
            head = current;
            while (next_next){
                next->next = next_next->next;
                next_next->next = next;
                current->next = next_next;

                current = current->next->next;
                next = current->next;
                if (next == NULL){
                    break;
                }
                next_next = next->next;
            };
            return head->next;

        }
};
