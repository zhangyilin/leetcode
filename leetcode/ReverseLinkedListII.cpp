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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (m==n)   return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* m_1 = dummy;
        ListNode* current;
        ListNode* grow;//grow initially point to n+1
        for (int i=1; i<=m-1; ++i){
            m_1 = m_1->next;
        }
        current = m_1->next;
        grow = current->next;
        for (int i=1; i<=n-m; ++i){
            grow = grow->next;
        }
        for (int i=m; i<=n; ++i){
            ListNode* next = current->next;
            current->next = grow;
            grow = current;
            current = next;
        }
        m_1->next = grow;
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
