/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Comp {
public:
    bool operator () (const ListNode* n1, const ListNode* n2) const {
        return n1->val > n2->val;
    }    
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<ListNode*> real_lists(0);
        for (int i=0; i<lists.size(); ++i){
            if (lists[i]){
                real_lists.push_back(lists[i]);
            }
        }
        if (real_lists.size() == 0){
            return NULL;
        }
        
        priority_queue <ListNode*, vector<ListNode*>, Comp> q (real_lists.begin(), real_lists.end());
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while (!q.empty()){
            ListNode* l = q.top();
            q.pop();
            if (l->next){
                q.push(l->next);
            }
            current->next = l;
            current = current->next;
        }
        return dummy->next;
        /*
        vector<ListNode*> frontier(0);
        for (int i=0; i<lists.size(); ++i){
            if (lists[i]){
                frontier.push_back(lists[i]);
            }
        }
        make_heap (frontier.begin(), frontier.end(), Comp());
        ListNode node(0);
        ListNode* head = &node;
        ListNode* current = head;
        while (!frontier.empty()){
            pop_heap(frontier.begin(), frontier.end());
            ListNode* next = frontier.front();
            frontier.pop_back();
            current->next = next;
            current = next;
            if (next->next){
                frontier.push_back(next->next);
                push_heap(frontier.begin(), frontier.end());
            }
        }
        return head->next;
        */
    }
};
