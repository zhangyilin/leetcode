/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = 0;
        ListNode* p = head;
        while (p){
            n++;
            p = p->next;
        }
        if (n==0){return NULL;}
        if (n==1){
            TreeNode* m = new TreeNode(head->val);
            return m;
        }
        p = head;
        for (int i=0; i<n/2-1; ++i){
            p = p->next;
        }
        ListNode* middle = p->next;
        p->next = NULL;
        TreeNode* left = sortedListToBST(head);
        TreeNode* right = sortedListToBST(middle->next);
        TreeNode* m = new TreeNode(middle->val);
        m->left = left;
        m->right = right;
        return m;
    }
};
