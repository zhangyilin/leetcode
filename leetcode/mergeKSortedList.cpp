/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MyComp {
    public:
        bool operator () (ListNode* & lfs, ListNode* & rhs) const{
            return lfs->val > rhs->val;
        }
};
class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n=lists.size();
            priority_queue<ListNode*, vector<ListNode*>, MyComp> tops;
            for (int i=0; i<n; ++i){
                ListNode* ln = lists[i];
                if (ln) tops.push(ln);
            }
            ListNode * current = new ListNode(0);
            ListNode * head = current;

            while (!tops.empty()){
                ListNode* top = tops.top();
                tops.pop();
                if (top->next){
                    tops.push(top->next);
                }
                ListNode * next = new ListNode(top->val);
                current->next = next;
                current = next;
            }
            current = head;
            head = head->next;
            delete current;
            return head;

        }
};
