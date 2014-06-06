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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (k==0 || head==NULL)   return head;
        
        ListNode* counter = head;
        int n=0;
        while(counter){
            n++;
            counter = counter->next;
        }
        k = k%n;
        k = n-k;
        ListNode* kp;
        ListNode* current = head;
        while (k){
            if (current->next == NULL){
                current = head;
            }else{
                current = current->next;
            }
            k--;
        }
        kp = current;
        while (current->next){
            current = current->next;
        }
        current->next = head;
        while (current->next != kp){
            current = current->next;
        }
        current->next = NULL;
        return kp;
    }
};
