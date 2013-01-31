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
            if (n==0) return head;
            ListNode * ptr1 = head;
            ListNode * ptr2 = head;
            n = n+1;
            while (n && ptr2!= NULL){
                ptr2 = ptr2->next;
                n--;
            }
            if (n != 0){
                return head->next;
            }
            while (ptr2 != NULL){
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
            //ptr1 = ptr2->next;
            //delete ptr1;
            ptr1->next = ptr1->next->next;
            return head;
        }
};
