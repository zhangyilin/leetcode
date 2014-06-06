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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while (l1 && l2){
            if (l1->val < l2->val){
                current->next = l1;
                l1 = l1->next;
            }else{
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1){
            while(l1){
                current->next = l1;
                l1 = l1->next;
                current = current->next;
            }
        }
        if (l2){
            while(l2){
                current->next = l2;
                l2 = l2->next;
                current = current->next;
            }
        }
        current = dummy->next;
        delete dummy;
        return current;
    }
};
