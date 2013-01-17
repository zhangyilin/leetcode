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
        TreeNode *sortedArrayToBST(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = num.size();
            if (n<=0){
                return NULL;
            }
            return helper(num, 0, n-1); 
        }
        TreeNode *helper (vector<int> &num, int left, int right){
            if (left > right){
                return NULL;
            }
            int root = left + (right-left+1)/2;
            TreeNode * pleft = helper(num, left, root-1);
            TreeNode * pright = helper(num, root+1, right);
            TreeNode * proot = new TreeNode(num[root]);
            proot->left = pleft;
            proot->right = pright;
            return proot;
        }

};
