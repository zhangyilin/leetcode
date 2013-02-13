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
        int MaxHeight (TreeNode * root){
            if (root == NULL){
                return 0;
            }
            int height = 0;
            height = max (height, MaxHeight(root->left));
            height = max (height, MaxHeight(root->right));
            return height+1;
        }
        bool isBalanced(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (root == NULL){
                return true;
            }
            if (abs(MaxHeight(root->left)-MaxHeight(root->right)) > 1){
                return false;
            }else {
                return isBalanced(root->left) && isBalanced(root->right);
            }
        }

};
