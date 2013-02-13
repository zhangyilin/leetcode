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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (!l1){    
                return l2;
            }
            if (!l2){
                return l1;
            }
            ListNode* l3 = NULL;
            ListNode* l_start = NULL;
            int carry = 0;
            while (l1 || l2){
                ListNode * l3_next = new ListNode(0);
                if (l3){
                    l3 -> next = l3_next;
                }else{//First time enter while loop
                    l_start = l3_next;
                }
                l3 = l3_next;
                int number_1 =0, number_2 =0, number_3 =0;
                if (l1){
                    number_1 = l1->val;
                    l1 = l1->next;
                }
                if (l2){
                    number_2 = l2->val;
                    l2 = l2->next;
                }
                number_3 = (number_1+number_2+carry) % 10;
                carry = (number_1+number_2+carry) / 10;
                l3 -> val = number_3;
            }
            if (carry){
                l3 -> next = new ListNode(1);
            }
            return l_start;
        }
};
