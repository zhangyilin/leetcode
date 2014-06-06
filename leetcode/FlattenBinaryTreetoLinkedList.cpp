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
    void flatten(TreeNode* root, TreeNode*& tail){
        if (root==NULL){
            tail = NULL;
            return;
        }
        TreeNode* left_tail(NULL);
        TreeNode* right_tail(NULL);
        flatten (root->left, left_tail);
        flatten (root->right, right_tail);
        if (root->left != NULL){
            if (root->right){
                tail = right_tail;
            }else{
                tail = left_tail;
            }
            left_tail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }else{
            if (root->right){
                tail = right_tail;
            }else{
                tail = root;
            }
        }
    }
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root)  return;
        TreeNode* tail(NULL);
        flatten (root, tail);
        return;
    }
};
