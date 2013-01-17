#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = 0;
            ListNode * p = head;
            while (p != NULL){
                n++;
                p = p->next;
            };
            return sortedListToBST(head, 0, n-1);
        }
        TreeNode *sortedListToBST(ListNode *&current, int start, int end){
            if (start > end){
                return NULL;
            }
            int middle = start + (end-start)/2;
            TreeNode * pleft = sortedListToBST (current, start, middle-1);
            TreeNode * parent = new TreeNode (current->val);//current point at middle now
            parent->left = pleft;
            current = current->next;
            TreeNode * pright = sortedListToBST (current, middle+1, end);
            parent->right = pright;
            return parent;
        }
};
int main(){
    ListNode * l1 = new ListNode(3);
    ListNode * l2 = new ListNode(5);
    ListNode * l3 = new ListNode(8);
    l1->next = l2;
    l2->next = l3;
    Solution s;
    s.sortedListToBST (l1);
}
